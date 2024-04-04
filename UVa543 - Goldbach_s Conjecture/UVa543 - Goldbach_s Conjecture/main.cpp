#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, primeTable[100000], index = 0;
    bool prime[1000001];
    memset(prime, true, sizeof(prime));
    for(int i=2; i<=1000000; i++){
        if(prime[i]){
            primeTable[index++] = i;
            for(int j=i+i; j<=1000000; j+=i)
                prime[j] = false;
        }
    }
    while(scanf("%d", &n) != EOF && n != 0){
        for(int i=0; i<index; i++){
            if(prime[n - primeTable[i]]){
                printf("%d = %d + %d\n", n, primeTable[i], n - primeTable[i]);
                break;
            }
        }
    }
    return 0;
}


