#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int fMonth, fDay, sMonth, sDay;
		scanf("%d %d %d %d", &fMonth, &fDay, &sMonth, &sDay);
		
		if(fMonth == sMonth){
			Answer = sDay - fDay + 1;
			cout << "#" << test_case+1 <<" "<<Answer<<endl;
			continue;
		}

	
		while(fMonth != sMonth){
			switch(fMonth){
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10: 
					Answer+=31-fDay;
					fMonth++;
					fDay = 0;
					break;
					
				case 2:
					Answer+=28-fDay;
					fMonth++;
					fDay=0;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					Answer+=30-fDay;
					fMonth++;
					fDay = 0;
					break;
					
				case 12:
					Answer+=31-fDay;
					fMonth = 1;
					fDay = 0;
					break;
			}
		}
		
		Answer+=sDay+1;
		
		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
