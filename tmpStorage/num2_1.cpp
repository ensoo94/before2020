#include <iostream>
#include <vector>
using namespace std;
int Answer;
vector<int> arr;

void solution(vector<int> arr){	
	for(int i=-1000; i<=1000; i++){ //공차  
		for(int j=-1000; j<=1000;j++){ //초항  
			int cntNum = 0;
			int tmpNum = j;
			for(int k=0; k<arr.size();k++){
				if(tmpNum<-1000 || tmpNum>1000){
					cntNum = 987654321;
					break; 
				}
				if(tmpNum != arr[k]){
					cntNum++;
				}
				tmpNum+=i;
			}
			if(Answer > cntNum) Answer = cntNum;
		}
	}
}

int main(){
	
	arr.clear();
	
	arr.push_back(1);
	arr.push_back(10);
	arr.push_back(2);
	arr.push_back(12);
	arr.push_back(3);
	arr.push_back(14);
	arr.push_back(7);
	arr.push_back(16);
	
	Answer = arr.size();
	
	solution(arr);
	cout<<"Answer: "<<Answer;
	return 0;
}
