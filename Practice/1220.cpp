#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int arr[101][101];
int Answer;

int main(int argc, char** argv)
{
	for(int test_case = 0; test_case  < 10; test_case++)
	{
		memset(arr, 0, sizeof(arr));
		Answer = 0;
		int tblNum;
		scanf("%d", &tblNum);
		
		for(int i=0;i<tblNum;i++){
			for(int j=0;j<tblNum;j++){
				scanf(" %d", &arr[i][j]);
			}
		}
		
		for(int k=0;k<tblNum-1;k++){
			for(int l=0;l<tblNum;l++){
				if(arr[k][l] == 1){
					for(int n=k+1;n<tblNum;n++){
						if(arr[n][l]==1) break;
						if(arr[n][l] == 2){
							Answer++;
							break;
						}
					}
				}
			}
		}

		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
