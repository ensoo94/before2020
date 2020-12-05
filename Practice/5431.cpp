#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;
vector<int> arr;
int check[101];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		arr.clear();
		memset(check, 0, sizeof(check));
		
		int sNum, yesMan;
		scanf("%d %d ", &sNum, &yesMan);
		
		for(int i=0;i<yesMan;i++){
			int tempNum;
			scanf(" %d", &tempNum);
			check[tempNum-1] = 1;
		}
		
		for(int j=0;j<sNum;j++){
			if(check[j] == 0){
				arr.push_back(j);
			}
		}

		cout << "#" << test_case+1;
		
		for(int k=0;k<arr.size();k++){
			printf(" %d", arr[k]+1);
		}
		printf("\n");
	}

	return 0;
}
