#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int Answer;

int mulfunc(int indexNum, int mulNum){
	if(mulNum == 1) return indexNum;
	return indexNum*mulfunc(indexNum, mulNum-1);
}

int main(int argc, char** argv)
{
	for(int test_case = 0; test_case  < 10; test_case++)
	{
		Answer = 0;
		int test_num;
		cin>>test_num;
		
		int indexNum, mulNum;
		scanf(" %d %d", &indexNum, &mulNum);
		Answer = mulfunc(indexNum, mulNum);

		cout << "#" << test_num <<" "<<Answer<<endl;
	}

	return 0;
}
