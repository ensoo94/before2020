#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;
int check[22];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		char arr[150];
		memset(check, 0, sizeof(check));
		
		string tempStr;
		cin>>tempStr;
		
		for(int i=0;i<tempStr.length();i++){
			arr[i] = tempStr[i];
		}
		
		int hNum, tempHip;
		cin>>hNum;
		
		for(int j=0;j<hNum;j++){
			scanf(" %d", &tempHip);
			check[tempHip]++;
		}


		cout << "#" << test_case+1 <<" ";
		
		for(int k=0;k<tempStr.length();k++)
		{
			for(int m=0;m<check[k];m++){
				printf("-");
			}
			printf("%c", arr[k]);
		}
		for(int l=0;l<check[tempStr.length()];l++){
			printf("-");
		}
		printf("\n");
	}

	return 0;
}
