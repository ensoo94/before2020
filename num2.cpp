#include <iostream>
#include <vector>
using namespace std;
int Answer;
vector<int> arr;

int getChangeNum(vector<int> arr, int subNum, int st){
	 int tempNum = arr[st];
	 int cntNum = 0 ;
	 while(st != 0){
	 	tempNum-=subNum;
	 	st--;
	 }
	 
	 for(int k=0;k<arr.size();k++){
	 	if(tempNum != arr[k]){
	 		cntNum++;
		 }
		 tempNum+=subNum;
	 }
	 
	 return cntNum;
}

void solution(vector<int> arr){
	for(int i=0;i<arr.size()-1;i++){
		for(int j=i+1;j<arr.size();j++){
			if((arr[j]-arr[i])%(j-i) == 0){
				int subNum = (arr[j]-arr[i])/(j-i);
				int changeNum = getChangeNum(arr, subNum, i);
				if(Answer > changeNum) Answer = changeNum;
			}else{
				continue;
			}
		}
	}
}

int main(){
	
	arr.clear();
	
	arr.push_back(1);
	arr.push_back(10);
	arr.push_back(3);
	arr.push_back(12);
	arr.push_back(5);
	arr.push_back(14);
	arr.push_back(7);
	//arr.push_back(16);
	
	Answer = arr.size();
	
	solution(arr);
	cout<<"Answer: "<<Answer;
	return 0;
}
