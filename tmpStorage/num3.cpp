#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>
#include <stdlib.h>
using namespace std;


string fibo(uint64_t n){
	if(n == 0){
		return "A";
	}
	if(n == 1){
		return "B";
	}
	
	string temp1, temp2, result;
	temp1 = fibo(0);
	temp2 = fibo(1);
	
	for(int i=2;i<=n;i++){
		result = temp1 + temp2;
		temp1 = temp2;
		temp2 = result;
	}
	
	result[result.length()] = '\0';
	return result;
}

char solve(uint64_t n, uint64_t x){
	vector<unsigned long long> f;
	f.resize(n+1);
	f[0] = f[1] = (unsigned long long)1;
	
	for(uint64_t i=2; i<=n; i++){
		f[i] = f[i-2]+f[i-1];
	}
	
	uint64_t tempSum = 0;
	uint64_t k;
	
	if(n >= 3){
		for(uint64_t i=2; i<=n; i++){
			tempSum+=f[i];
			if(tempSum >= x){
				k = i;
				tempSum-=f[i];
				break;
			}
		}
		
		x-=tempSum;
		while(k>=2){
			if(f[k-2] < x){
				x-=f[k-2];
				k-=1;
			}else if(f[k-2] >= x){
				k-=2;
			}
		}
		
			if(k == 1){
				return 'B';
			}
			
			if(k == 0){
				return 'A';
			}
	}
	return fibo(n).at(x);
}

int main(){
//	char* result = new char[9];
	cout<<fibo(7)<<endl;
	cout<<solve(7, 9f)<<endl;

	return 0;
}
