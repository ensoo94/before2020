#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<char> arr;
	arr.push_back('1');
	arr.push_back('2');
	arr.push_back('3');
	arr.push_back('4');
	for(int i=1; i<(1<<arr.size());i++){
		for(int j=0; j<arr.size(); j++){
			if(i & (1<<j)){
				cout<< arr[j] <<", ";
			}
		}
		cout<<endl;
	}
}
