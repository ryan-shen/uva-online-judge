#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, dp[10001];
    dp[0] = 1;
    for(int i=1; i<=10000; i++){
        int temp = dp[i - 1] * i;
        while(temp % 10 == 0) temp /= 10;
        dp[i] = temp % 100000;
    }
    while(scanf("%d", &n) != EOF){
        printf("%5d -> %d\n", n, dp[n] % 10);
    }
    return 0;
}


