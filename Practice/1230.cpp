#include <cstdio>
#include <iostream>
using namespace std;

typedef struct list{
	int data;
	struct list* next;
}node;

typedef struct linkedlist{
	struct list* head;
}Linkedlist;

void insertNode(Linkedlist* l, int data, int flag){
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	
	if(l->head == NULL){
        l->head = newNode;
        return;
    }else if(flag == 0){
		newNode->next = l->head;
		l->head = newNode;
	}else if(flag == -1){
		node* ptr = l->head;
		while(ptr->next!=NULL) {
                ptr = ptr->next;
            }
            ptr->next = newNode;
	}else{
		node* ptr = l->head;
		for(int i=0;i<flag-1;i++){
			ptr = ptr->next;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
}

void addNode(Linkedlist* l, int data){
	node* ptr = l->head;
	
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	
	ptr->next = newNode;
}

void deleteNode(Linkedlist* l, int flag){
	node* ptr = l->head;
	for(int i=0;i<flag-1;i++){
		ptr = ptr->next;
	}
	ptr->next = ptr->next->next;
}

int main(void)
{
	setbuf(stdout, NULL);
	for(int test_case = 0; test_case  < 10; test_case++)
	{
		int len;

		Linkedlist* l = new Linkedlist;
		l->head = NULL;
		
		scanf("%d", &len);
		
		
		for(int i=0;i<len;i++){
			int tmpNum;
			scanf("%d", &tmpNum);
			insertNode(l, tmpNum, -1);
		}
		int commNum;
		scanf("%d", &commNum);
		
		for(int j=0;j<commNum;j++){	
			char tmpComm;		
			scanf("\n %c", &tmpComm);
			if(tmpComm == 'I'){
				int beginNum, endNum;
				scanf("%d %d ", &beginNum, &endNum);
					for(int n=0;n<endNum;n++){
						int tmpp;
						scanf("%d ", &tmpp);
						insertNode(l, tmpp, beginNum+n);
					}
			}else if(tmpComm == 'A'){
				int endNum;
				scanf( "%d ", &endNum);
					for(int k=0;k<endNum;k++){
						int tmpp;
						scanf("%d ", &tmpp);
						addNode(l, tmpp);
					}
			}else if(tmpComm == 'D'){
				int beginNum, endNum;
				scanf("%d %d ", &beginNum, &endNum);
					for(int m=0;m<endNum;m++){
						deleteNode(l, beginNum);
					}
			}else {
				printf("error\n");
			}
		}
		
		
		printf("#%d", test_case+1);
		node* ptr = l->head;
		for(int k=0;k<10;k++){
			printf(" %d ", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
		delete(l);
	}
	return 0;
}
