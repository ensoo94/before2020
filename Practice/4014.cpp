#include <iostream>
#include <string.h>
#include <cstdio>
#include <cmath>
using namespace std;
int Answer;
int map[21][21];
bool pos[21], slope[21];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		memset(map, 0, sizeof(map));
		
		int N, X;
		cin>>N>>X;
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				scanf(" %d", &map[i][j]);
			}
		}
		
		int idx=0;

		while(idx != N){ //row check
			int cnt = 1;
			memset(pos, false, sizeof(pos));
			memset(slope, false, sizeof(slope));
			
			for(int k=1;k<=N;k++){
				if(k == N){
					//printf("%d : ok!\n", idx);
					Answer++;
					break;
				}
				
				bool _end = false;
				if(abs(map[idx][k]-map[idx][k-1])>1) break;
				
				if(map[idx][k] == map[idx][k-1]){
					if(!slope[k] && !slope[k-1]) cnt++;
					if(cnt >= X){
						pos[k+1] = true;
					}
				}else if(map[idx][k] > map[idx][k-1]){
					if(!pos[k]) break;
					for(int l=1;l<=X;l++){
						slope[k-l] = true;
					}
					cnt = 1;
				}else if(map[idx][k] < map[idx][k-1]){
					if(N-k < X) break;
					for(int s=0;s<X-1;s++){
						if(map[idx][k+s] != map[idx][k+s+1]){
							_end = true;
							break;
						}
						slope[k+s] = true;
					}
					slope[k+X-1] = true;
					cnt = 1;
					if(_end) break;
				}
			}
			
			idx++;
		}
		
		idx=0; 
		while(idx != N){ //column check
			int cnt = 1;
			memset(pos, false, sizeof(pos));
			memset(slope, false, sizeof(slope));
			
			for(int k=1;k<=N;k++){
				if(k == N){
					Answer++;
					break;
				}
				
				bool _end = false;
				if(abs(map[k][idx]-map[k-1][idx])>1) break;
				
				if(map[k][idx] == map[k-1][idx]){
					if(!slope[k] && !slope[k-1]) cnt++;
					if(cnt >= X){
						pos[k+1] = true;
					}
				}else if(map[k][idx] > map[k-1][idx]){
					if(!pos[k]) break;
					for(int l=1;l<=X;l++){
						slope[k-l] = true;
					}
					cnt = 1;
				}else if(map[k][idx] < map[k-1][idx]){
					if(N-k < X) break;
					for(int s=0;s<X-1;s++){
						if(map[k+s][idx] != map[k+s+1][idx]){
							_end = true;
							break;
						}
						slope[k+s] = true;
					}
					slope[k+X-1] = true;
					cnt = 1;
					if(_end) break;
				}
			}
			
			idx++;
		}

		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
