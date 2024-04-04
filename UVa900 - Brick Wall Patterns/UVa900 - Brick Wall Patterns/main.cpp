#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    long long dp[51];
    dp[0] = dp[1] = 1;
    for(int i=2; i<51; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    while(scanf("%d", &n) != EOF && n != 0)
        printf("%lld\n", dp[n]);
    return 0;
}


