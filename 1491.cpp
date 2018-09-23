#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
unsigned long long Answer;
long long a, b, n;

unsigned long long calMin(long long rowNum, long long colNum){
	unsigned long long temp;
	temp = a*abs(rowNum-colNum) + b*(n-rowNum*colNum);
	return temp;
}

int main(void)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 2e9;
		scanf("%d %d %d", &n, &a, &b);
		unsigned long long temp;

		for(int i=1;i<=sqrt(n);i++){
			for(int j=1;j<=n;j++){
				if(i*j<=n){
					temp =  calMin(i, j);
					if(temp < 0) continue;
					if(temp < Answer) Answer = temp;
				}else break;
			}
		}

		printf("#%d %llu\n", test_case+1, Answer);
	}

	return 0;
}
