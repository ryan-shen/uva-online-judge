#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, test = 1;
    char s[1005];
    while(scanf("%s", s) != EOF){
        if(s[0] == 'e' && s[1] == 'n' && s[2] == 'd')
            break;
        int dp[1005], maxValue = 1;
        n = strlen(s);
        for(int i=0; i<1005; i++)
            dp[i] = 1;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(s[i] < s[j])
                    dp[j] = max(dp[j], dp[i] + 1);
            }
            maxValue = max(maxValue, dp[i + 1]);
        }
        printf("Case %d: %d\n", test++, maxValue);
    }
    return 0;
}


