#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;
int Answer;
int arr[101];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		memset(arr, 0, sizeof(arr));
		
		int tNum;
		cin>>tNum;
		
		for(int i=0;i<1000;i++){
			int tempNum;
			scanf(" %d", &tempNum);
			arr[tempNum]++;
		}		
		
		int temp = 0;
		
		for(int j=0;j<101;j++){
			if(temp <= arr[j]){
				Answer = j;
				temp = arr[j];
			}
		}

		cout << "#" << tNum <<" "<<Answer<<endl;
	}

	return 0;
}
