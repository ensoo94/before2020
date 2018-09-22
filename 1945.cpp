#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int Answer[6];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		memset(Answer, 0, sizeof(Answer));
		int whatNum;
		cin>>whatNum;
		
		while(whatNum != 1){
			if(whatNum % 11 == 0){
				whatNum/=11;
				Answer[4]++;
				
			}
			if(whatNum % 7 == 0){
				whatNum/=7;
				Answer[3]++;
				
			}
			if(whatNum % 5 == 0){
				whatNum/=5;
				Answer[2]++;
				
			}
			if(whatNum % 3 == 0){
				whatNum/=3;
				Answer[1]++;
				
			}
			if(whatNum % 2 == 0){
				whatNum/=2;
				Answer[0]++;
				
			}
		}

		cout << "#" << test_case+1<<" ";
		for(int i=0;i<5;i++){
			cout<<Answer[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
