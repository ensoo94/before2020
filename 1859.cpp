#include <iostream>
#include <vector>
using namespace std;
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int daysNum, tempNum;
        int tempSum = 0;
		Answer = 0;
        vector<int> arr;
		cin>>daysNum;

        for(int i=0;i<daysNum;i++){
            cin>>tempNum;
            arr.push_back(tempNum);
        }

        for(int j=daysNum-1;j>=0;j--){ //Greedy Algorithm
            if(tempSum > arr[j]){
                Answer += tempSum - arr[j];
            } else {
                tempSum = arr[j];
            }
        }

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}