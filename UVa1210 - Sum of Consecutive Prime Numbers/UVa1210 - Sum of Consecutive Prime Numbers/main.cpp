#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[10001] = {0}; //答案表
    int primeTable[1231]; //質數表
    int index = 0, n;
    //建質數表
    bool num[10001];
    memset(num, true, sizeof(num));
    for(int i=2; i<=10000; i++){
        if(num[i]){
            primeTable[index++] = i;
            for(int j=i+i; j<=10000; j+=i){
                num[j] = false;
            }
        }
    }
    //求 1~i 的前綴和
    int dp[index];
    dp[0] = primeTable[0];
    for(int i=1; i<index; i++)
        dp[i] = dp[i - 1] + primeTable[i];
    //連續質數的和填表
    for(int i=0; i<index-1; i++){
        for(int j=i; j<index; j++){
            if(i){
                if(dp[j] - dp[i - 1] <= 10000)
                    arr[dp[j] - dp[i - 1]]++;
            }
            else{
                if(dp[j] <= 10000)
                    arr[dp[j]]++;
            }
        }
    }
    
    while(scanf("%d", &n) != EOF && n != 0)
        printf("%d\n", arr[n]);
    return 0;
}


