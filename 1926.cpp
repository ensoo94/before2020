#include <iostream>
#include <vector>
using namespace std;
int count;

void countNum(int i){
    if(i == 0) return;
    if(i%10 == 3 || i%10 == 6 || i%10 == 9) count++;
    countNum(i/10);
}

int main(int argc, char** argv)
{
	int T;
    cin>>T;

    for(int i=1; i<=T; i++){
        count=0;

        countNum(i);

        if(count>0){
            for(int j=0;j<count;j++){
                cout<<"-";
            }
        }else{
            cout<<i;
        }
        cout<<" ";
    }

	return 0;
}
