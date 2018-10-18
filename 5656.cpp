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

void copyMap(){
	for(int i=0; i<H; ++i){
		for(int j=0;j<W;++j){
			aftermap[i][j] = map[i][j];
		}
	}
}

void down_block() {
	queue<int> qt;
	for(int i=0;i<W;i++){
		for(int j=0;j<H;++j){
			if(aftermap[j][i] != 0){
				qt.push(aftermap[j][i]);
			}
		}
		
		for(int k=0; k<H; k++){
			if(k<H-qt.size()){
				aftermap[k][i] = 0;
			}else{
				aftermap[k][i] = qt.front();
				qt.pop();
			}
		}
	}
}

void solve(int idx){
	if(idx == N){ //떨군 벽돌 순서 기록 끝나면 
		copyMap();
		
		for(int j=0;j<N;j++){ //저장된 순서대로 떨구기 시작 
			int pos = dropx[j]; 
			int posx;
			for(int k=0;k<H;k++){ //제일 위의 벽돌 찾기
				if(aftermap[k][pos] > 0){
					posx = k;
					break;
				}
			}
			
			if(aftermap[posx][pos] == 1){ // 하나만
				aftermap[posx][pos] = 0;
			}else{ // 여러 개
				memset(visited, false, sizeof(visited));
				q.push(make_pair(posx, pos));
				while(!q.empty()){
					int tx = q.front().first;
					int ty = q.front().second;
					int count = aftermap[tx][ty];
					visited[tx][ty] = true;
					q.pop();
							
					for(int four=0;four<4;four++){ // 네 방향 다 체크
						int nx = tx;
						int ny = ty; 
						for(int wow=0;wow<count-1;++wow){ //count 만큼 깊숙히
							nx+=dx[four];
							ny+=dy[four];
									
							if(nx >= 0 && nx < H && ny >=0 && ny < W){
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
		for(int yeax = 0; yeax<H; ++yeax){
			for(int yeay = 0; yeay<W; ++yeay){
				if(aftermap[yeax][yeay] != 0){
					temp++;
				} 
			}
		}
		
		if(temp < Answer){
			Answer = temp;
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
		
		Answer = 99999;
		
		scanf(" %d %d %d", &N, &W, &H);
		
		for(int i=0; i<H; ++i){
			for(int j=0;j<W;++j){
				scanf(" %d", &map[i][j]);
			}
		}
		
		solve(0);
		
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
