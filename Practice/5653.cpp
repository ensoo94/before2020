#include <iostream>
#include <queue>
#include <string.h>
#include <cstdio>
#include <vector>
#define MAX 500
using namespace std;
queue< pair<int, int> > q;
int visited[MAX][MAX], map[MAX][MAX], life[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int tmpK;
vector<int> tempx, tempy;

void printTable(int k, int temp){
	printf("Time : %d\n", k-temp);
	for(int i=240;i<260;++i){
		for(int j=240;j<260;++j){
			printf("%d ", life[i][j]);
		}
		printf("\n");
	}
}

int solve(int k){
	tmpK = k;
	while(k--){
		int cursize = q.size();
		for(int i=0;i<cursize;++i){
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			if(map[x][y] == life[x][y]){
				if(visited[x][y] == 1){
					for(int j=0;j<4;j++){
						if(life[x][y] > life[x+dx[j]][y+dy[j]] && visited[x+dx[j]][y+dy[j]] == 0){
							if(map[x+dx[j]][y+dy[j]] != -1){
								if(map[x+dx[j]][y+dy[j]] < 2*life[x][y]){
									life[x+dx[j]][y+dy[j]] = life[x][y];
									map[x+dx[j]][y+dy[j]] = 2*life[x][y];
								}
							}else{
								if(map[x+dx[j]][y+dy[j]] < 2*life[x][y]){
									map[x+dx[j]][y+dy[j]] = 2*life[x][y];
									life[x+dx[j]][y+dy[j]] = life[x][y];
									tempx.push_back(x+dx[j]);
									tempy.push_back(y+dy[j]);
									q.push(make_pair(x+dx[j], y+dy[j]));
								}
							}	
						}
					}
				}
			}
			map[x][y]--;
			if(map[x][y] > 0 && visited[x][y]){
				q.push(make_pair(x, y));
			}
		}
	//	printTable(tmpK, k);
	//	printf("\n");
		for(int g=0;g<tempx.size();++g){
			visited[tempx[g]][tempy[g]] = 1;
		}
		tempx.clear();
		tempy.clear();
		
	}
	return q.size();	
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		memset(visited, 0, sizeof(visited));
		memset(map, -1, sizeof(map));
		memset(life, 0, sizeof(life));
		
		// input
		int n, m, k;
		scanf(" %d %d %d", &n, &m, &k);
		
		for(int i=0;i<n;i++){
			int tx = MAX/2 -2/n + i;
			for(int j=0;j<m;j++){
				int ty = MAX/2- 2/m + j;
				int input;
				scanf(" %d", &input);
				
				if(input != 0){
					map[tx][ty] = input*2;
					q.push(make_pair(tx, ty));
					visited[tx][ty] = 1;
					life[tx][ty] = input;
				}
				
			}
		}

		int Answer = solve(k);
		printf("#%d %d\n",test_case+1, Answer);
		
		// initialize
		while(q.size() != 0){
			q.pop();
		}
	}

	return 0;
}
