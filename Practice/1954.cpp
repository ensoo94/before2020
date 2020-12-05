#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int cnt;
int arr[10][10];

void solve(){
	int switchNum = 1;
	int num = 1;
	int i=0; 
	int j=-1;
	
	while(1){
		for(int p=0;p<cnt;p++){
			j+=switchNum;
			arr[i][j] = num;
			num++;
		}
		
		cnt--;
		if(cnt == 0) break;
		
		for(int p=0;p<cnt;p++){
			i+=switchNum;
			arr[i][j] = num;
			num++;
		}
		
		switchNum = -switchNum;
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		cin>>cnt;
		int temp = cnt;
		
		solve();
		
		//print arr
		cout << "#" << test_case+1 <<endl;
		
		for(int m = 0; m<temp; m++){
			for(int n=0; n<temp; n++){
				printf("%d ", arr[m][n]);
			}
			printf("\n");
		}
	}

	return 0;
}
