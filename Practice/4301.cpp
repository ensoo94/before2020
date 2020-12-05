#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;
int Answer;
int arr[1001][1001];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		memset(arr, 0, sizeof(arr));
		
		int width, height;
		cin>>width>>height;
		
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				if(arr[i][j] == 0){ //unvisited
					arr[i][j] = 2; //possible
					if(i+2 < height){
						arr[i+2][j] = 1; //impossible
					}
					if(j+2 < width){
						arr[i][j+2] = 1;
					}
				}
			}
		}
		
		for(int i=0;i<height;i++){
			for(int j=0;j<width;j++){
				if(arr[i][j] == 2){
					Answer++;
				}
			}
		}

		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
