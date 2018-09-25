#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<char> Answer;

void eraseSame(int strSize){
	for(int k = 0; k<strSize-1; k++){
		if(Answer[k] == Answer[k+1]){
			Answer.erase(Answer.begin()+k);
			Answer.erase(Answer.begin()+k);
			break;
		}
	}
	if(strSize-2<0) return;
	eraseSame(strSize-2);
}


int main(int argc, char** argv)
{
	for(int test_case = 0; test_case  < 10; test_case++)
	{
		char tempChar;
		int charNum;
		scanf("%d", &charNum);
		Answer.clear();
		
		for(int i=0;i<charNum;i++){
			scanf(" %1c", &tempChar);
			Answer.push_back(tempChar);
		}	
		
		eraseSame(charNum);

		cout << "#" << test_case+1<<" ";
		vector<char>::iterator it;
		for(it=Answer.begin();it<Answer.end();it++){
			cout<<*it;
		}
		printf("\n");
	}

	return 0;
}
