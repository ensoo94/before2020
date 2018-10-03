#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> grade;
int max_diff, Answer;

void solution(vector<int> grade, int max_diff){
	int temp = 0;
	sort(grade.begin(), grade.end());
	int left = 0;
	int right = 0;
	
	while(1){
		temp = right-left;
		if(left > right || right >= grade.size()){
			if(temp > Answer) Answer = temp;
			break;
		}
		if(grade[right]-grade[left] <= max_diff){
			right++;
			continue;
		}
		if(grade[right] - grade[left] > max_diff){
			if(temp > Answer) Answer = temp;
			temp = 0;
			left++;
		}
	}	
	
}

int main(){
	Answer = 0;
	grade.clear();
	grade.push_back(5);
	grade.push_back(1);
	grade.push_back(3);
	grade.push_back(4);
	
	solution(grade, 2);
	cout<<"Answer: "<<Answer;
	return 0;
}
