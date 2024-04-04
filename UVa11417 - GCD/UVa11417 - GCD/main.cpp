#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int GCD(int a, int b){
    while(b % a){
        int temp = b % a;
        b = a;
        a = temp;
    }
    return a;
}
int main(int argc, const char * argv[]) {
    int n, dp[501][501];
    
    for(int i=1; i<500; i++)
        for(int j=i+1; j<=500; j++)
            dp[i][j] = GCD(i, j);
    
    while(scanf("%d", &n) != EOF && n != 0){
        int sum = 0;
        for(int i=1; i<n; i++)
            for(int j=i+1; j<=n; j++)
                sum += dp[i][j];
        printf("%d\n", sum);
    }
    return 0;
}

