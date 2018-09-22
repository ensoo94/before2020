#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int Answer, tempMax, tempMin;
int boxArr[101];

void findIndex(){
	for(int k = 0; k<100 ; k++){
		if(boxArr[k] <= boxArr[tempMin]) tempMin = k;
		if(boxArr[k] >= boxArr[tempMax]) tempMax = k;
	}
}

int main(int argc, char** argv)
{
	int test_case, dumpNum;
	
	for(test_case = 0; test_case  < 10; test_case++)
	{
		Answer = 100;
		cin>>dumpNum;
		tempMax = 0;
		tempMin = 0;
		
		for(int i=0; i<100; i++){
			scanf("%d", &boxArr[i]);
		}
		
		while(dumpNum--){
			findIndex();
			boxArr[tempMax]--;
			boxArr[tempMin]++;
		}
		
		findIndex();
		Answer = boxArr[tempMax] - boxArr[tempMin];
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
