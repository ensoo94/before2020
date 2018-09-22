#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;
int Answer;
int arr[100][100];

int main(int argc, char** argv)
{
	int T, temp;
	
	for(int l=0;l<10;l++){
		cin>>T;
		Answer = 0;
		memset(arr, 0, sizeof(arr));
		for(int i=0;i<100;i++) //input and check row
		{
			for(int j=0;j<100;j++)
			{
				scanf("%d", &arr[i][j]);
				temp+=arr[i][j];
			}
			if(temp > Answer) Answer = temp;
			temp = 0;
		}
		cout<<"row max: "<<Answer<<endl;
		//check col
		for(int m=0;m<100;m++) 
		{
			for(int n=0;n<100;n++)
			{
				temp+=arr[n][m];
			}
			if(temp > Answer) Answer = temp;
			temp = 0;
		}
		cout<<"col max: "<<Answer<<endl;
		
		//check cross 1
		for(int r=0;r<100;r++){
			temp+=arr[r][r];
		}
		if(temp > Answer) Answer = temp;
		temp = 0;
		
		//check cross 2
		for(int k=0;k<100;k++){
			temp+=arr[k][100-k];
		}
		if(temp > Answer) Answer = temp;
		temp = 0;
		
		cout<<"cross max: "<<Answer<<endl;
		
		cout<<"#"<<T<<" "<<Answer<<endl;
	}

	return 0;
}
