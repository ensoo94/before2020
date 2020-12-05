#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int tNum, caLimit;
		cin>>tNum>>caLimit;
		
		int arr[tNum+1][2];
		
		for(int i=0;i<tNum;i++){
			scanf(" %d %d", &arr[i][0], &arr[i][1]);
		}
		
		for(int k=1; k<(1<<tNum);k++){
			int tempCal = 0;
			int tSum = 0;
			for(int j=0; j<tNum; j++){
				if(k & (1<<j)){
					tempCal+=arr[j][1];
					tSum+=arr[j][0];
					if(tempCal > caLimit){
						tempCal=0;
						tSum=0;
						break;
					}
				}
			}
			if(tSum > Answer){
				Answer = tSum;
			}
		}		
		
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
