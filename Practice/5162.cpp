#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		Answer = c/min(a, b);
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}
	return 0;
}
