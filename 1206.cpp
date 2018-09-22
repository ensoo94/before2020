#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int Answer;
int builArr[1001], tempArr[1001];

int main(int argc, char** argv)
{
	int T, test_case;
	
	for(test_case = 0; test_case  < 10; test_case++)
	{
		Answer = 0;
		int builNum;
		cin>>builNum;
		
		for(int i=0;i<builNum;i++){
			scanf("%d", &builArr[i]);
		}
		
		for(int k=0;k<builNum;k++){
			tempArr[k] = builArr[k];
		}
		
		for(int j=2;j<builNum-2;j++){
			while(1){
				if(tempArr[j]>builArr[j-1] && 
					tempArr[j]>builArr[j-2] &&
					tempArr[j]>builArr[j+1] &&
					tempArr[j]>builArr[j+2]){
						Answer++;
						tempArr[j]--;
					}else{
						tempArr[j] = builArr[j];
						break;
					}
			}
		}
		
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
