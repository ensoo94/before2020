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
		int arr[8];
		for(int i=0;i<7;++i){
			scanf(" %d", &arr[i]);
		}
		
		vector<int> temp;
		temp.clear();
		
		for(int j=0;j<5;++j){
			for(int m=j+1;m<6;++m){
				for(int n=m+1;n<7;++n){
					int tNum = arr[j]+arr[m]+arr[n];
					temp.push_back(tNum);
				}
			}
		}
		sort(temp.begin(), temp.end());
		temp.erase(unique(temp.begin(), temp.end()), temp.end());

        printf("#%d %d\n", test_case+1, *(temp.rbegin()+4));
	}

	return 0;
}
