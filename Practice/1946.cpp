#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;
char Answer[30][10];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		memset(Answer, '0', sizeof(Answer));
		int letNum;
		cin>>letNum;
		
		char letter;
		int howNum, temp;
		temp = 10;
		int x = 0;
		
		for(int i=0;i<letNum;i++){
			cin>>letter>>howNum;
			
			while(howNum--){
				Answer[x][10-temp] = letter;			
				temp--;
				if(temp == 0){
					x++;
					temp = 10;
				}
			}
		}
		

		cout << "#" << test_case+1 <<endl;
		for(int k=0;k<=x;k++){
			for(int l=0;l<10;l++){
				if(Answer[k][l] == '0') break;
				printf("%c", Answer[k][l]);
			}
			printf("\n");
		}
	}

	return 0;
}
