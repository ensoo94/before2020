#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int arr[10000][2];
int arr_rev[10000];
int alist_t1[10000], alist_t2[10000];
int queue[10000];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		memset(arr, 0, sizeof(arr));
		memset(arr_rev, 0, sizeof(arr_rev));
		memset(alist_t1, 0, sizeof(alist_t1));
		memset(alist_t2, 0, sizeof(alist_t2));
		memset(queue, 0, sizeof(queue));
		
		int pNum, eNum, t1, t2;
		scanf(" %d %d %d %d", &pNum, &eNum, &t1, &t2);	
		
		// #1 Input edge	
		for(int i=0;i<eNum;i++){
			int u, v;
			cin>>u>>v;
			if(arr[u][0] == 0){
				arr[u][0] = v;
			}else{
				arr[u][1] = v;
			}
			arr_rev[v] = u;
		}
		
		// #2 Find parents of t1
		int now = t1;
		alist_t1[0] = t1;
		int t1_length = 1;
		while(now != 1){
			now = arr_rev[now];
			alist_t1[t1_length] = now;
			t1_length++;
		}
		
		// #3 Find parents of t2
		now = t2;
		alist_t2[0] = t2;
		int t2_length = 1;
		while(now != 1){
			now = arr_rev[now];
			alist_t2[t2_length] = now;
			t2_length++;
		}
		
		// #4 Find common ancestor
		int ancestor=1;
		if(alist_t2[0] != 1){
			int check = 0;
			for(int m=0;m<t1_length;m++){
				if(m == t1_length-1 && alist_t1[m] == ancestor) break;
				if(check == 1) break;
				
				for(int n=0;n<t2_length;n++){
					if(alist_t1[m] == alist_t2[n]){
						ancestor = alist_t2[n];
						check = 1;
						break;
					}
				}
			}
		}
		
		// #5 Count children
		int cnt = 1;
		int front = 0;
		
		queue[0] = ancestor;
		while(cnt != front){
			int index = queue[front];
			if(arr[index][0] != 0){
				queue[cnt] = arr[index][0];
				cnt++;
			}
			if(arr[index][1] != 0){
				queue[cnt] = arr[index][1];
				cnt++;
			}
			front++;
		}

		printf("#%d %d %d\n", test_case+1, ancestor, cnt);
	}

	return 0;
}
