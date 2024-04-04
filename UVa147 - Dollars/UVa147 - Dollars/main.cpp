#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
long long int dp[30001] = {0};
int coin[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
void init(){
    dp[0] = 1;
    for(int i=0; i<11; i++){
        for(int j=coin[i]; j<=30000; j++){
            dp[j] += dp[j - coin[i]];
        }
    }
}
int main(int argc, const char * argv[]) {
    int n, m;
    init();
    while (scanf("%d.%d", &n, &m) != EOF && !(n == 0 && m == 0)) {
        printf("%3d.%02d%17lld\n", n, m, dp[n*100 + m]);
    }
    return 0;
}

