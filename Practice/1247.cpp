#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;
int Answer = 999;
int cusNum;
bool check[10];
typedef struct axisSet{
    int x;
    int y;
}setNum;

setNum beginNum, endNum;
setNum arr[10];

int calDistance(setNum a, setNum b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}

void dfs(int y, int sum, int cnt){
    if(cnt == cusNum){
        sum+= calDistance(arr[y], endNum);
        if(Answer > sum) Answer = sum;
        return;
    }

    for(int x=0; x<cusNum; x++){
        if(!check[y]){
            check[y] = true;
            sum+= calDistance(arr[x], arr[y]);
            if(sum < Answer){
                dfs(x, sum, cnt+1);
            }

            check[y] = false;
            sum-=calDistance(arr[x], arr[y]);
        }
    }
}


int main(int argc, char** argv)
{
	int T, test_case;
    int sum=0;
	
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 999999;
        cin>>cusNum;

        scanf("%d %d %d %d", &beginNum.x, &beginNum.y, &endNum.x, &endNum.y);
        for(int i = 0; i<cusNum; i++){
            scanf("%d %d", &arr[i].x, &arr[i].y);
        }

        for(int j = 0; j<cusNum; j++){
            sum = calDistance(beginNum, arr[j]);
            dfs(j, sum, 0);
        }

		cout << "#" << test_case+1<<" "<< Answer << endl;
	}

	return 0;
}
