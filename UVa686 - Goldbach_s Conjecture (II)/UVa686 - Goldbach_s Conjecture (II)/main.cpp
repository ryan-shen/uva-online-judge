#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, maxN = 32770, primeTable[5000], index = 0, dp[maxN];
    bool prime[maxN];
    memset(prime, true, sizeof(prime));
    memset(dp, 0, sizeof(dp));
    for(int i=2; i<maxN; i++){
        if(prime[i]){
            primeTable[index++] = i;
            for(int j=i+i; j<maxN; j+=i)
                prime[j] = false;
        }
    }
    for(int i=0; i<index; i++){
        for(int j=i; j<index; j++){
            if(primeTable[i] + primeTable[j] < maxN)
                dp[primeTable[i] + primeTable[j]]++;
        }
    }
    while(scanf("%d", &n) != EOF && n != 0){
        printf("%d\n", dp[n]);
    }
    return 0;
}


