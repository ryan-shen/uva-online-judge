#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, maxN = 1001, dp[maxN][2700];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i=1; i<maxN; i++){
        for(int j=0; j<2700; j++){
            dp[i][j] += dp[i - 1][j] * i;
            dp[i][j + 1] += dp[i][j] / 10;
            dp[i][j] %= 10;
        }
    }
    while(scanf("%d", &n) != EOF){
        printf("%d!\n", n);
        bool lead = false;
        for(int i=2699; i>=0; i--){
            if(dp[n][i])
                lead = true;
            if(lead)
                printf("%d", dp[n][i]);
        }
        printf("\n");
    }
    return 0;
}


