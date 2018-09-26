#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;
string arr[11]= {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
int Answer[11];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		memset(Answer, 0, sizeof(Answer));
		string test_num;
		cin>>test_num;
		
		int cntNum;
		scanf(" %d", &cntNum);
		
		
		for(int i=0;i<cntNum;i++){
			string tmpChar;
			cin>>tmpChar;
			for(int j=0;j<10;j++){
				if(tmpChar.compare(arr[j])==0){
					Answer[j]++;
					break;
				}
			}
		}

		cout<<test_num;
		printf("\n");
		for(int k=0;k<10;k++){
			while(Answer[k]){
				printf("%s ", arr[k].c_str());
				Answer[k]--;
			}
		}
	}

	return 0;
}
