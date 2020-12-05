#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int Answer;
int arr[10001];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		memset(arr, 0, sizeof(arr));
		
		int testNum, tmpNum;
		cin>>testNum;
		
		printf("#%d ", test_case+1);
		arr[0] = 1;
		
		for(int i=0;i<testNum;i++){
			scanf(" %d", &tmpNum);
			for(int k=9999;k>=0;k--){
				if(arr[k] == 1){
					arr[k+tmpNum] = 1;
				}
			}
		}
		
		for(int m=0;m<10000;m++){
			if(arr[m] == 1){
				Answer++;
			}
		}
		printf("%d\n", Answer);

	//	cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
