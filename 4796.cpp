#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int mNum;
		cin>>mNum;
		int arr[mNum+1];
		
		int d1, d2, u, check;
		d1=d2=u=check=0;
		
		for(int i=0;i<mNum;i++){
			scanf(" %d", &arr[i]);
			if(i>=2){
				if(arr[i-2]>arr[i-1] && arr[i-1]<arr[i]){ // v
					if(check == 0){
						d1 = i-1;
					}else{
						d2 = i-1;
						int temp = (d2-u)*(u-d1);
						Answer+=temp;
						d1 = d2;
						d2 = 0;
						check = 0;
					}
				}else if(arr[i-2]<arr[i-1] && arr[i-1]>arr[i]){ // ^
					u = i-1;
					check = 1;
				}
			}
		}
		
		if(check == 1 && d2 == 0){
			d2 = mNum-1;
			int tempNum = (d2-u)*(u-d1);
			Answer+=tempNum;
		}
		
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
