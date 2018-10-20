#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <string.h>
#include <cmath> 
using namespace std;
int Answer;
int map[11][11][10];
int check[11][11]; //충전기 수  
int capacity[10], dist[10];
int M, A;
queue<int> qa, qb;
int dx[5] = {0, -1, 0, 1, 0};
int dy[5] = {0, 0, 1, 0, -1};

vector<pair<int, int> > p;

int calDist(int x1, int y1, int x2, int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int findMin(){
	int temp = 500;
	int min;
	for(int i=0;i<A;i++){
		if(capacity[i] < temp){
			min = i;
			temp = capacity[i];
		}
	}
	return min;
}

void printMap(){
	int cnt = 0;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;++j){
			printf("%d ", check[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int findMax(int x, int y){
	int max = findMin();
	if(check[x][y]>0){
		for(int i=0;i<A;++i){
			if(map[x][y][i] == 1){
				if(capacity[max] < capacity[i]) max = i;
			}
		}
	}
	return max;
}

int findSecond(int x, int y){
	int max = findMin();
	if(check[x][y]>0){
		for(int i=0;i<A;++i){
			if(map[x][y][i] == 1){
				if(capacity[i] != capacity[findMax(x, y)]){
					if(capacity[max] < capacity[i]) max = i;
				}
			}
		}
	}
	return max;
}

void moveMan(){
	int ax = 0;
	int ay = 0;
	int bx = 9;
	int by = 9;
	
	// 시작위치 충전 가능 체크
	if(check[ax][ay]){
		Answer+=capacity[findMax(ax, ay)];
	}
	if(check[bx][by]){
		Answer+=capacity[findMax(bx, by)];
	}

	//printf("first A: %d\n", findMax(ax, ay));
	//printf("first B: %d\n", findMax(bx, by));

	while(!qa.empty() && !qb.empty()){
		int ma = qa.front();
		qa.pop();
		int mb = qb.front();
		qb.pop();
		
		ax+=dx[ma];
		ay+=dy[ma];
		
		bx+=dx[mb];
		by+=dy[mb];
		
		if(check[ax][ay]>0 && check[bx][by]>0){
			if(findMax(ax, ay) == findMax(bx, by)){ //동시에 접할 때 
				if(check[ax][ay] == 1 && check[bx][by] == 1){
					Answer+=capacity[findMax(ax, ay)];
				}else if(check[ax][ay] == 1 && check[bx][by]>1){
					Answer+=capacity[findMax(ax, ay)];
					Answer+=capacity[findSecond(bx, by)];
				}else if(check[ax][ay]>1 && check[bx][by] == 1){
					Answer+=capacity[findMax(ax, ay)];
					Answer+=capacity[findSecond(ax, ay)];
				}else if(check[ax][ay]>1 && check[bx][by]>1){
					Answer+=capacity[findMax(ax, ay)];
					Answer+=max(capacity[findSecond(ax, ay)], capacity[findSecond(bx, by)]);
				}
			}else{
				Answer+=capacity[findMax(ax, ay)];
				Answer+=capacity[findMax(bx, by)];
			}
		}else if(check[ax][ay]>0 && check[bx][by] == 0){
			Answer+=capacity[findMax(ax, ay)];
		}else if(check[ax][ay]==0 && check[bx][by]>0){
			Answer+=capacity[findMax(bx, by)];
		}
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		memset(map, 0, sizeof(map));
		memset(check, 0, sizeof(check));
		memset(capacity, 0, sizeof(capacity));
		memset(dist, 0, sizeof(dist));
		
		scanf(" %d %d", &M, &A);
		int tempMove;
		
		//input moving
		for(int i=0;i<M;i++){
			cin>>tempMove;
			qa.push(tempMove);
		}
		
		for(int j=0;j<M;j++){
			scanf(" %d", &tempMove);
			qb.push(tempMove);
		}
		
		
		int tx, ty;
		//input charger info
		for(int k=0;k<A;k++){
			scanf(" %d %d %d %d", &tx, &ty, &dist[k], &capacity[k]);
			p.push_back(make_pair(ty-1, tx-1));
		}
		
		//make bc map
		for(int m=0;m<10;m++){ //row, ty-1
			for(int n=0;n<10;n++){ //col
				for(int l=0;l<A;l++){
					if(calDist(m, n, p[l].first, p[l].second) <= dist[l]){
						map[m][n][l] = 1;
						check[m][n]++;
					}
				}
			}
		}
		
		//moving and check
		moveMan();
	//	printMap();
		p.clear();
		
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
