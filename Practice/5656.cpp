#include <iostream>
#include <queue>
#include <cstdio>
#include <string.h>
using namespace std;
int N, W, H, Answer;
int map[20][20], aftermap[20][20], visited[20][20];
int dropx[5];
int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};
queue< pair<int, int> > q;
bool _end;

void copyMap(){
	for(int i=1; i<=H; ++i){
		for(int j=0;j<W;++j){
			aftermap[i][j] = map[i][j];
		}
	}
}

void printMap(){
	for(int i=1; i<=H; ++i){
		for(int j=0;j<W;++j){
			printf("%d ", aftermap[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void down_block() {
	queue<int> qt;
	for(int i=0;i<W;i++){
		for(int j=1;j<=H;++j){
			if(aftermap[j][i] != 0){
				qt.push(aftermap[j][i]);
			}
		}
		
		for(int k=1; k<=H; k++){
			if(k<H-qt.size()+1){
				aftermap[k][i] = 0;
			}else{
				aftermap[k][i] = qt.front();
				qt.pop();
			}
		}
	}
}

void solve(int idx){
	if(_end == true) return;
	if(idx == N){ //떨군 벽돌 순서 기록 끝나면 
		copyMap();
		bool _noblock = false;
		for(int j=0;j<N;j++){ //저장된 순서대로 떨구기 시작 
			int pos = dropx[j]; 
			int posx;
			for(int k=0;k<=H;k++){ //제일 위의 벽돌 찾기
				if(aftermap[k][pos] > 0){
					posx = k;
					break;
				}
				if(k == H && aftermap[k][pos] == 0){
					_noblock = true;
					break;
				}
			}
			
			if(_noblock) break;
			if(aftermap[posx][pos] == 1){ // 하나만 
				aftermap[posx][pos] = 0;
				continue;
			}else{ // 여러 개 
				memset(visited, false, sizeof(visited));
				q.push(make_pair(posx, pos));
				while(!q.empty()){
					int tx = q.front().first;
					int ty = q.front().second;
					int count = aftermap[tx][ty];
					visited[tx][ty] = true;
					aftermap[tx][ty] = 0;
					q.pop();
							
					for(int four=0;four<4;four++){ // 네 방향 다 체크
						int nx = tx;
						int ny = ty; 
						for(int wow=1;wow<count;++wow){ //count 만큼 깊숙히
							nx+=dx[four];
							ny+=dy[four];
									
							if(nx >= 1 && nx <= H && ny >=0 && ny < W){
								if(!visited[nx][ny] && aftermap[nx][ny] > 0){
									visited[nx][ny] = true;
									if(aftermap[nx][ny] == 1){
										aftermap[nx][ny] = 0;
									}else{
										q.push(make_pair(nx, ny));
									}
								}
							}else{
								break; // 범위 넘어가면 그만
							}
							
						}
					}
				}
			}					
			down_block();
		} 
		
		int temp = 0; // 남은 벽돌 세기 	
		for(int yeax = 1; yeax<=H; ++yeax){
			for(int yeay = 0; yeay<W; ++yeay){
				if(aftermap[yeax][yeay] != 0){
					temp++;
				} 
			}
		}
		
		if(temp < Answer){
			Answer = temp;
		}
		
		if(temp == 0){
			_end = true;
		}
		
		return;	
	}
	
	for(int i=0;i<W;i++){ // 떨군 위치 순서 저장 
		dropx[idx] = i;
		solve(idx+1);
	}
	return;
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		memset(map, 0, sizeof(map));
		memset(aftermap, 0, sizeof(map));
		memset(dropx, 0, sizeof(dropx));
		
		Answer = 99999;
		
		scanf(" %d %d %d", &N, &W, &H);
		
		for(int i=1; i<=H; ++i){
			for(int j=0;j<W;++j){
				scanf(" %d", &map[i][j]);
			}
		}
		_end = false;
		solve(0);
		
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
