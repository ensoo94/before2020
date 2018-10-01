#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;
 
int Answer;
int cost['z'+1];
int memotmp[2001][2001];
string tmpStr;
 
 
int solve(int bNum, int eNum){
    if(bNum >= eNum) return 0;
     
    int &result = memotmp[bNum][eNum];
    if(result != -1) return result; //?
     
     
    if(tmpStr[bNum] == tmpStr[eNum]){
        result = solve(bNum+1, eNum-1);
    }else{
        result = 987654321;
    }
     
    result = min(result, solve(bNum+1, eNum)+cost[tmpStr[bNum]]);
    result = min(result, solve(bNum, eNum-1)+cost[tmpStr[eNum]]);
         
    return result;
}
 
 
int main()
{
    int T, test_case;
     
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        memset(cost, 0, sizeof(cost));
        memset(memotmp, -1, sizeof(memotmp));
         
        int l, k;
        cin>>l>>k;
         
        int tmpp, tmpm;
         
        cin>>tmpStr;
         
        for(int j=0;j<k;j++){
            scanf(" %d %d", &tmpp, &tmpm);
            cost[j+'a'] =  min(tmpp, tmpm);
        }
         
        Answer = solve(0, l-1);
         
 
        cout << "#" << test_case+1 <<" "<<Answer<<endl;
    }
 
    return 0;
}
