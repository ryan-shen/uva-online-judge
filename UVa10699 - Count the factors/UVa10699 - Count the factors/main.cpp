#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int maxN = 1000001, n;
    bool primeTable[maxN];
    memset(primeTable, true, sizeof(primeTable));
    for(int i=2; i<maxN; i++){
        if(primeTable[i]){
            for(int j=i+i; j<maxN; j+=i)
                primeTable[j] = false;
        }
    }
    while(scanf("%d", &n) != EOF && n != 0){
        int count = 0;
        for(int i=2; i<=n; i++){
            if(primeTable[i]){
                if(n % i == 0)
                    count++;
            }
        }
        printf("%d : %d\n", n, count);
    }
    return 0;
}

