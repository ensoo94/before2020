#include <iostream>
#include <vector>
#include <cstdio>
#define MAX 100005
#define MAXM 300005
using namespace std;
typedef struct edge{
	int x, y, w;
	int prv;
}g;

g arr[2*MAXM];
int to[MAX];
int Q[50*MAX];
int front, rear;
int inQ[MAX];
long long inf = 1e18;
long long dp[MAX];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		int pNum, eNum, bNum, fNum;
		scanf(" %d %d %d %d", &pNum, &eNum, &bNum, &fNum);
		for(int j=1;j<=pNum;j++){
			to[j] = 0;
			dp[j] = inf;
			inQ[j] = 0;
		}
		
		for(int k=1; k<=2*eNum; k++){
			arr[k].prv = 0;
		}
		
		for(int i=1;i<=eNum;i++){
			scanf(" %d %d %d", &arr[i].x, &arr[i].y, &arr[i].w);
			arr[i+eNum].x = arr[i].y;
			arr[i+eNum].y = arr[i].x;
			arr[i+eNum].w = arr[i].w;
			arr[i].prv = to[arr[i].x]; // #1
			to[arr[i].x] = i; // #2
		}		
		
		for(int l=eNum+1; l<=eNum*2; l++){
			arr[l].prv = to[arr[l].x]; // == to[arr[i].y]  #1, #2 นÝบน 
			to[arr[l].x] = l; 
		} 
		
		front = 0;
		rear = 0;
		dp[bNum] = 0;
		inQ[bNum] = 1;
		Q[0] = bNum;
		
		while(front <= rear){
			int x = Q[front++]; // #3
			inQ[x] = 0;
			
			for(int m = to[x]; m; m=arr[m].prv){ // #4
				int y = arr[m].y;
				int w = arr[m].w;
				if(dp[y]>dp[x]+w){
					dp[y] = dp[x]+ w;
					if(!inQ[y]){
						Q[++rear] = y; // #5
						inQ[y] = 1;
					}
				}
			}
		}
		long long Answer = dp[fNum];
		if(Answer == inf) Answer = -1;

		printf("#%d %lld\n", test_case+1, Answer);
	}

	return 0;
}
