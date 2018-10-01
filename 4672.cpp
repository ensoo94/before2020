#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;
int Answer;
int arr[26];

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		string tmpStr;
		cin>>tmpStr;
		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < tmpStr.size(); i++) arr[tmpStr.at(i) - 97]++; //0 = a의 수, 1 = b의 수... 
		for (int j = 0; j < 26;j++) Answer += ((arr[j] * (arr[j] + 1)) / 2);


		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
