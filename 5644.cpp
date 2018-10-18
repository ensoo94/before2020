#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath> 
using namespace std;
int Answer;
int map[11][11];

 
typedef struct Point{
	int x;
	int y;	
}point;

int calDist(point p1, point p2){
	return abs(p1.x-p2.x)+abs(p1.y-p1.y);
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		


		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
