#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        int arr[n], maxSum = 0, dp[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        
        dp[0] = arr[0];
        for(int i=1; i<n; i++)
            dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        for(int i=0; i<n; i++)
            maxSum = max(maxSum, dp[i]);
        
        if(maxSum > 0)
            printf("The maximum winning streak is %d.\n", maxSum);
        else
            printf("Losing streak.\n");
    }
    return 0;
}

