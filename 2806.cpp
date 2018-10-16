#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int Answer;
static int cnt = 0;
int N, Row[100] = { 0 };

void printResult(){
	
	/*printf("%3d Result : ", cnt++);
	for(int i=1;i<=N;i++){
		printf("(%d, %d) ", i, Row[i]);
	}
	cout<<endl;*/
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
		cnt++;
		return;
	}
	
	for(int i=1;i<=N;++i){
		Row[q+1] = i;
		queens(q+1);
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		cnt = 0;
		cin>>N;
		queens(0);
		cout << "#" << test_case+1 <<" "<<cnt<<endl;
	}

	return 0;
}
