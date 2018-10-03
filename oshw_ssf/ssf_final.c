#define FUSE_USE_VERSION 26

#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>


int inode_num = 0;	//give the unique number(ino) to each snode, never be decreased

struct _snode
{
	char* name;				//file or dir name
	struct stat st;				//inode number, will be struct stat st
	int child_num;				//directory only: number of children(file and directory)
	struct _snode* pchild;		//directory only: pointer of the first child(like the head pointer of linked list)
	struct _snode* parent;
	struct _snode* prev;
	struct _snode* next;
};
typedef struct _snode snode;

snode* root;

struct _data
{
	int st_ino;
	char* data;
	struct _data* prev;
	struct _data* next;
};
typedef struct _data data;

struct _datalist
{
	data* head;
	data* current;
	data* tail;
};
typedef struct _datalist datalist;

datalist dlist;

/* Datalist */

data* make_data(int ino) // make data
{
	data* newData = (data*)calloc(1, sizeof(data));
	newData->data = NULL;
	newData->st_ino = ino;
	newData->prev = NULL;
	newData->next = NULL;

	return newData;
}

void insert_data(data* newNode) //insert data into datalist
{
	if(dlist.head == NULL)
	{
		dlist.head = newNode;
		dlist.current = dlist.head;
		dlist.tail = newNode;
	}
	else
	{
		dlist.tail->next = newNode;
		newNode->prev = dlist.tail;
		dlist.tail = newNode;
	}

	return;
}

void delete_data(data* ndata) //delete data from datalist
{

	if(dlist.head == ndata)
    {
        dlist.head = dlist.head->next;

        if(dlist.head != NULL)
        {
            dlist.head->prev = NULL;
            ndata->prev = NULL;
            ndata->next = NULL;
        }
    }
    else{
        data* temp = ndata;
        if(ndata->prev != NULL)
        {
            ndata->prev->next = temp->next;
        }
        if(ndata->next != NULL)
        {
            ndata->next->prev = temp->prev;
        }
    }

    free(ndata->data);
    free(ndata);

    return;
}

data* search_data(int ino) //search data from datalist by inode number
{
    if(dlist.head == NULL)
    {
        return NULL;	//no data
    }

    dlist.current = dlist.head;
    while(dlist.current != NULL && dlist.current->st_ino < ino)
    {
        if(dlist.current->next==NULL){break;}
        dlist.current = dlist.current->next;
    }

    if(dlist.current->st_ino == ino)
    {
        return dlist.current;
    }
    else{
        return NULL;	//does not exist
    }
}

/* snode */

snode* make_snode(char* name, mode_t mode, uid_t uid, gid_t gid) //make snode and insert new data into datalist
{
	snode* new = (snode*)calloc(1, sizeof(snode));
	new->name = (char*)calloc(1, sizeof(char)*(strlen(name)+1));
	strcpy(new->name, name);
	new->st.st_ino = inode_num++;
	new->st.st_mode = mode;
	if(S_ISDIR(mode))
	{
		new->st.st_nlink = 2;
	}
	else
	{
		new->st.st_nlink = 1;
	}
	new->st.st_size = 0;

	new->st.st_atime = time(NULL);	//last access
	new->st.st_mtime = time(NULL);	//modified
	new->st.st_ctime = time(NULL);	//status changed
	new->child_num = 0;

	new->pchild = new->parent = new->prev = new->next = NULL;

	data* newData = make_data(new->st.st_ino);
	insert_data(newData);

	return new;
}

void insert_snode(snode* parent, snode* new) //insert snode into tree
{
	if(S_ISREG(parent->st.st_mode))	//cannot insert node into a regular file
	{
		return;	//error
	}

	if(parent->child_num == 0)
	{
		parent->pchild = new;
		new->parent = parent;
		new->prev = new->next = NULL;
		parent->child_num++;
	}
	else if(parent->child_num == 1)
	{
		parent->pchild->next = new;
		new->prev = parent->pchild;
		parent->pchild->prev = new;
		new->next = parent->pchild;
		new->parent = parent;
		parent->child_num++;
	}
	else
	{
		new->next = parent->pchild;
		new->prev = parent->pchild->prev;
		new->prev->next = new;
		parent->pchild->prev = new;
		new->parent = parent;
		parent->child_num++;
	}
	return;
}

void delete_snode(snode* node) //delete file, empty directory snode
{
	if(node == NULL)
	{
		return;	//does not exist
	}

	if(S_ISDIR(node->st.st_mode) && node->child_num != 0)
	{
		return;	//when dir is not empty
	}

	if(node->parent->child_num == 1)	//the only child
	{
		node->parent->pchild = NULL;
		node->parent->child_num--;

	}
	else if(node->parent->child_num == 2)
	{
		if(node->parent->pchild == node)	//deleting node is pchild
		{
			node->parent->pchild = node->next;	//move pchild
		}
		node->parent->pchild->next = node->parent->pchild->prev = NULL;
		node->parent->child_num--;
	}
	else
	{
		if(node->parent->pchild == node)
		{
			node->parent->pchild = node->next;	//move pchild
		}
		node->next->prev = node->prev;
		node->prev->next = node->next;
		node->parent->child_num--;

	}

	free(node);

	return;
}

snode* search_snode(char* name, snode* search_dir)	//search at the given directory search_dir : search start point, with only file name
{
	snode* res = NULL;
	snode* cur = search_dir->pchild;

	if(cur == NULL)
	{
		return res;	//not exist
	}

	if(S_ISREG(search_dir->st.st_mode))	//reg file
	{
		return res;
	}

	do
	{
		if(strcmp(cur->name, name) == 0)
		{
			res = cur;
			return res;
		}
		else
		{
			cur = cur->next;
		}
	}while(cur != search_dir->pchild && cur != NULL);

	return res;
}

snode* search_snode_path(const char* path, snode* root)	//search from root always by path
{
	snode* res = root;
	char* cpath = (char*)malloc(sizeof(char)*strlen(path));
	strcpy(cpath, path);

	char* t = strtok(cpath+1, "/");	//cpath+1: except root
	if(t!=NULL)
	{
		res = search_snode(t, res);
		if(res == NULL)
		{
			return res;	//no result
		}
	}

	while(t!=NULL)
	{
		t = strtok(NULL, "/");
		if(t!=NULL)
		{
			res = search_snode(t, res);
		}

		if(res == NULL)
		{
			return NULL;	//no result
		}
	}

	return res;
}

char* get_child_name(char* path) // get child snode's name
{
	int len = strlen(path);
	char* npath = (char*)malloc(sizeof(char)*strlen(path));
	strcpy(npath, path);

	char* p = &npath[len-1];
	do
	{
		p--;
	}while(*p != '/');
	char* child = p;
	do
	{
		p--;
	}while(*p != '/');
	char *parent = p;

	parent = strtok(parent+1, "/");
	*child = '\0';
	child = strtok(child+1, "/");

	return child;
}

char* get_parent_name(char* path) // get parent snode's name
{
	int len = strlen(path);
	char* npath = (char*)malloc(sizeof(char)*strlen(path));
	strcpy(npath, path);

	char* p = &npath[len-1];
	do
	{
		p--;
	}while(*p != '/');
	char* child = p;
	do
	{
		p--;
	}while(*p != '/');
	char *parent = p;

	parent = strtok(parent+1, "/");
	*child = '\0';
	child = strtok(child+1, "/");

	return parent;
}

char* get_parent_path(char* path) // get parent snode's path
{
	int len = strlen(path);
	char* npath = (char*)malloc(sizeof(char)*strlen(path));
	strcpy(npath, path);

	char* p = &npath[len-1];
	do
	{
		p--;
	}while(*p != '/');
	char* child = p;
	do
	{
		p--;
	}while(*p != '/');
	char *parent = p;

	parent = strtok(parent+1, "/");
	*child = '\0';

	return npath;
}


/* fuse */

static int ssf_getattr(const char* path, struct stat* stbuf) // get metadata and save in stbuf
{
	int res = 0;
	snode* node = search_snode_path(path, root);
	if(node == NULL)
	{
		return -ENOENT;
	}

	memset(stbuf, 0, sizeof(struct stat));
	if(node!=NULL)
	{
		stbuf->st_ino = node->st.st_ino;
		stbuf->st_mode = node->st.st_mode;
		stbuf->st_size = node->st.st_size;
		stbuf->st_nlink = node->st.st_nlink;
		stbuf->st_uid = node->st.st_uid;
		stbuf->st_gid = node->st.st_gid;
		stbuf->st_atime = node->st.st_atime;
		stbuf->st_mtime = node->st.st_mtime;
		stbuf->st_ctime = node->st.st_ctime;
		return 0;
	}
	else
	{
		return -ENOENT;	//no such directory...
	}
}

static int ssf_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi) // read main information about file in directory
{
	(void) offset;
	(void) fi;

	snode* location = search_snode_path(path, root);
	snode* current;

	if(location==NULL)
	{
		return -ENOENT; //no such directory
	}
	if(!S_ISDIR(location->st.st_mode))
	{
		return -ENOTDIR;	//not a directory
	}

	filler(buf, ".", NULL, 0);	//current
	filler(buf, "..", NULL, 0);	//parent

	current = location->pchild;
	int i = 0;
	for(i=0; i<location->child_num; i++)
	{
		if(current!=NULL)
		{
			filler(buf, current->name, NULL, 0);
			current = current->next;
		}
	}

	return 0;
}

static int ssf_mkdir(const char *_path, mode_t mode) // make new directory
{
	char* path = (char*)malloc(sizeof(char) * (strlen(_path)+1));
	strcpy(path, _path);

	char* child = get_child_name(path);
	char* parent = get_parent_path(path);
	snode* newdir = make_snode(child, S_IFDIR | mode, getuid(), getgid());
	snode* pnode = search_snode_path(parent, root);
	pnode->st.st_nlink++;
	insert_snode(pnode, newdir);

	return 0;
}

static int ssf_create(const char* _path, mode_t mode, struct fuse_file_info* fi) // create new file with given mode
{
	if(search_snode_path(_path, root) != NULL)
	{
		return -EEXIST;	//file exist
	}
	char* path = (char*)malloc(sizeof(char) * (strlen(_path)+1));
	strcpy(path, _path);

	char* child = get_child_name(path);
	char* parent = get_parent_path(path);
	snode* newdir = make_snode(child, mode | O_RDWR, getuid(), getgid());
	snode* pnode = search_snode_path(parent, root);
	pnode->st.st_nlink++;
	insert_snode(pnode, newdir);

	return 0;
}

static int ssf_chmod(const char* path, mode_t mode) // change file mode
{
	snode* location = search_snode_path(path, root);

	if(location == NULL)
	{
		return -ENOENT;	//not exist
	}

	location->st.st_mode = location->st.st_mode | mode;
	return 0;
}

static int ssf_open(const char *_path, struct fuse_file_info *fi) // check error and copy file path
{
	char* path = (char*)malloc(sizeof(char) * strlen(_path));
	strcpy(path, _path);

	snode* location = search_snode_path(path, root);

	if(location == NULL)
	{
		return -ENOENT;	//not exist
	}

	if(S_ISDIR(location->st.st_mode) && (fi->flags & (O_WRONLY | O_RDWR)))
	{
		return -EISDIR;	//this is directory
	}

	return 0;
}

static int ssf_release(const char* path, struct fuse_file_info* fi) //close file
{
	(void)fi;
	(void) path;

	return 0;
}

static int ssf_rmdir(const char* path) // remove directory
{
	snode* todelete = search_snode_path(path, root);
	if(todelete == NULL)
	{
		return -ENOENT;	//directory not exist
	}
	if(todelete->child_num != 0)
	{
		return -ENOTEMPTY;
	}
	delete_snode(todelete);
	return 0;
}

static int ssf_unlink(const char* path) //remove file
{
	snode* todelete = search_snode_path(path, root);
	if(todelete == NULL)
	{
		return -ENOENT;	//directory not exist
	}
	delete_snode(todelete);
	return 0;
}

static int ssf_rename(const char* old, const char* new)	// change file name
{
	snode* node = search_snode_path(old, root);
	char* newname = get_child_name(new);

	if(node == NULL)
	{
		return -ENOENT;	//file not exist
	}

	node->name = (char*)realloc(node->name, sizeof(char) * (strlen(newname)+1));
	strcpy(node->name, newname);

	return 0;
}

static int ssf_read(const char *path, char *buf, size_t size, off_t offset) //read data from already opened file.
{
	int len;
	snode* node = search_snode_path(path, root);

	if(node==NULL)
	{
		return -ENOENT;
	}

	data* dnode = search_data(node->st.st_ino);

	if(dnode == NULL)
	{
		return -ENOENT;
	}

	len = node->st.st_size;
	if(offset<len)
	{
		if(offset + size > len)
		{
			size = len - offset;
		}
		memcpy(buf, dnode->data + offset, size);
	}
	else
	{
		size = 0;
	}

	return size;
}

static int ssf_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fi) //write data to already opened file.
{
	(void) fi;

	snode* node = search_snode_path(path, root);
	if(node == NULL)
	{
		return -ENOENT;
	}

	data* dnode = search_data(node->st.st_ino);

	if(dnode == NULL)
	{
		return -ENOENT;
	}

	dnode->data = (char*)realloc(dnode->data, size);
	strcpy(dnode->data, buf);
	node->st.st_size = size;
	return size;
}

static int ssf_utimens(const char* path, const struct timespec tv[2])
{
	return 0;
}

static int ssf_truncate(const char* path, off_t length)
{
	return 0;
}

static struct fuse_operations ssf_oper = {
	.getattr	= ssf_getattr,
	.readdir	= ssf_readdir,
	.mkdir 		= ssf_mkdir,
	.chmod 		= ssf_chmod,
	.open		= ssf_open,
	.release 	= ssf_release,
	.rmdir 		= ssf_rmdir,
	.rename 	= ssf_rename,
	.read		= ssf_read,
	.create 	= ssf_create,
	.utimens 	= ssf_utimens,
	.unlink 	= ssf_unlink,
	.write 		= ssf_write,
	.truncate 	= ssf_truncate,
};

int main(int argc, char *argv[])
{
	root = make_snode("/", S_IFDIR | 0755, getuid(), getgid());
	return fuse_main(argc, argv, &ssf_oper, NULL);
}
