#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;
int Answer;
string origNum, temp;

void changeNum(int index){
	Answer++;
	if(temp.at(index) == '0'){
		temp[index] = '1';
	}else if(temp.at(index) == '1'){
		temp[index] = '0';
	}
	
	if(index+1 == origNum.size()) return;
	
	for(int i = index+1; i<origNum.size(); i++){
		if(temp.at(i) != temp.at(index)){
			temp[i] = temp.at(index);
		}
	}
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		cin>>origNum;
		temp = origNum;
		
		for(int k = 0; k<temp.size(); k++){
			temp[k] = '0';
		}
		
		
		for(int j=0;j<origNum.size();j++){
			if(temp.compare(origNum) == 0){
				break;
			} 
			if(temp.at(j) != origNum.at(j)){
				changeNum(j);
			}
		}		

		cout << "#" << test_case+1 <<" "<<Answer<<endl;
	}

	return 0;
}
