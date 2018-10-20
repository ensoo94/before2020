#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int Answer;
int map[21][21];
bool visited[101];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};
int N;

void solve(int x, int y){
	int temp = 0;
	
	for(int i=1;i<N;++i){
		for(int j=1;j<N;++j){
			if(y+i<N && y-j>=0 && x+i+j<N && 2*(i+j)>Answer){
				memset(visited, false, sizeof(visited));
				visited[map[x][y]] = true;
				int nx, ny;
				bool check = false;
				//오른쪽 아래  
				for(int k=1;k<=i;k++){
					nx = x+dx[0]*k; 
					ny = y+dy[0]*k;
					if(visited[map[nx][ny]]){
						check = true;
						break;
					}
					visited[map[nx][ny]] = true;
				}
				if(check) continue;
				int nx1, ny1;
				
				//왼쪽 아래 
				for(int dl=1;dl<=j;++dl){
					nx1 = nx+dx[1]*dl;
					ny1 = ny+dy[1]*dl;
					if(visited[map[nx1][ny1]]){
						check = true;
						break;
					}
					visited[map[nx1][ny1]] = true;
				}
			//	if(check) continue;
				int nx2, ny2;
				
				//왼쪽 위  
				for(int ul=1;ul<=i;++ul){
					nx2 = nx1+dx[2]*ul;
					ny2 = ny1+dy[2]*ul;
					if(visited[map[nx2][ny2]]){
						check = true;
						break;
					}
					visited[map[nx2][ny2]] = true;
				}
				if(check) continue;
				int nx3, ny3;
				
				// 오른쪽 위 
				for(int ur=1;ur<j;++ur){
					nx3 = nx2+dx[3]*ur;
					ny3 = ny2+dy[3]*ur;
					if(visited[map[nx3][ny3]]){
						check = true;
						break;
					}
					visited[map[nx3][ny3]] = true;
				}
			//	printf("Start: %d, %d\n", x, y);
				if(check) continue;
				
				Answer = 2*(i+j);
			}
		}
	}
	
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		memset(map, 0, sizeof(map));
		//memset(visited, false, sizeof(visited));
		Answer = 0;
		
		cin>>N;
		
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				scanf(" %d", &map[i][j]);
			}
		}
		
		for(int m=0;m<N;++m){
			for(int k=0;k<N;++k){
				solve(m, k);
			}
		}
		
		if(Answer == 0) Answer = -1;
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
