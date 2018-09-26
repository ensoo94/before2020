#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> Answer;

int main(int argc, char** argv)
{
	for(int test_case = 0; test_case  < 10; test_case++)
	{
		int T, tempNum, result;
		cin>>T;
		
		Answer.clear();
		for(int i = 0; i<8; i++){
			scanf(" %d", &tempNum);
			Answer.push_back(tempNum);
		}
		
		int subNum = 1;
	
		while(1){
			result = Answer.front()-subNum;
			if(result <= 0){
				Answer.erase(Answer.begin());
				Answer.push_back(0);
				break;
			}
			
			Answer.erase(Answer.begin());
			Answer.push_back(result);
			subNum++;
			if(subNum == 6){
				subNum = 1;
			}
		}
	

		printf("#%d", T);
		vector<int>::iterator it;
		for(it = Answer.begin();it<Answer.end();it++){
			printf(" %d", *it);
		}
		printf("\n");
	}

	return 0;
}
