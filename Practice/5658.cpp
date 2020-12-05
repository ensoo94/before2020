#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
unsigned long long Answer;
vector<int> arr;
vector<unsigned long long> password;

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		arr.clear();
		password.clear();
		
		int tempChr, num, k;
		cin>>num>>k;
		
		for(int i=0;i<num;i++){
			scanf(" %1x", &tempChr);
			arr.push_back(tempChr);
		}
		
		int cnt = num/4;
	
		for(int j=0;j<cnt;j++){
			for(int m=0;m<4;m++){
				unsigned long long sum = 0;
				vector<int>::iterator index = arr.begin()+cnt*m;
				for(int n=0;n<cnt;n++){
					sum+=((*index)*pow(16, cnt-n-1));
					//cout<<*index<<" °ª°ú 16ÀÇ "<<cnt-k-1<<"½ÂÀ» °öÇÏ¸é "<<(*index)*pow(16, cnt-k-1)<<endl; 
					index++;
				}
				password.push_back(sum);
			}
			int beginNum = arr[0];
			arr.erase(arr.begin());
			arr.push_back(beginNum);
		}

		sort(password.begin(), password.end());
		password.erase(unique(password.begin(), password.end()), password.end());
		Answer = password[password.size()-k];
		
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
