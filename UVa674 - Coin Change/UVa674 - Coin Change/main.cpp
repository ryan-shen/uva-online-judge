#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, dp[7490];
    int coin[] = {1, 5, 10, 25, 50};
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i=0; i<5; i++)
        for(int j=coin[i]; j<7490; j++)
            dp[j] += dp[j - coin[i]];

    while(scanf("%d", &n) != EOF)
        printf("%d\n", dp[n]);
    return 0;
}


