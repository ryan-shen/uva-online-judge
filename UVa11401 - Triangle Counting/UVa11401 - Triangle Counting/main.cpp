#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, maxN = 1000001;
    long long dp[maxN], add = 0, layer = 0;
    memset(dp, 0, sizeof(dp));
    //累加序列為 1, 11, 121, 1221, 12321, 123321...
    for(int i=4; i<maxN; i++){
        if(i % 2 == 0)
            layer++;
        add += layer;
        dp[i] += dp[i - 1] + add;
    }
    while(scanf("%d", &n) != EOF && n >= 3)
        printf("%lld\n", dp[n]);
    return 0;
}

