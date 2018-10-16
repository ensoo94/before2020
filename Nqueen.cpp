#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int N, Row[100] = { 0 };

void printResult(){
	static int cnt = 1;
	printf("%3d Result : ", cnt++);
	for(int i=1;i<=N;i++){
		printf("(%d, %d) ", i, Row[i]);
	}
	cout<<endl;
}

bool promising(int q){
	for(int i=1; i<q; ++i){
		if(Row[q] == Row[i] || abs(Row[q]-Row[i]) == abs(q-i)){
			return false;
		}
	}
	return true;
}

void queens(int q) {
	if(!promising(q)) return;
	if(q == N){
		printResult();
		return;
	}
	
	for(int i=1;i<=N;++i){
		Row[q+1] = i;
		queens(q+1);
	}
}

int main(){
	cin>>N;
	queens(0);
	return 0;
}
