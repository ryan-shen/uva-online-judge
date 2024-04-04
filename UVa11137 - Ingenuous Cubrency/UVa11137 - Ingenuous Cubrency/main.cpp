#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    int currency[] = {1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 9261};
    long long dp[10001] = {1};
    
    for(int i=0; i<21; i++)
        for(int j=currency[i]; j<10001; j++)
            dp[j] += dp[j - currency[i]];
        
    while(scanf("%d", &n) != EOF)
        printf("%lld\n", dp[n]);
    return 0;
}

