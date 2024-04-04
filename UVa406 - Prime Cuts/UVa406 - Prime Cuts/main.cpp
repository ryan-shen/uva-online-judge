#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, c, primeTable[500], primeIndex = 1;
    bool prime[1201];
    memset(prime, true, sizeof(prime));
    primeTable[0] = 1;
    for(int i=2; i<=1200; i++){
        if(prime[i]){
            primeTable[primeIndex++] = i;
            for(int j=i+i; j<=1200; j+=i)
                prime[j] = false;
        }
    }
    while(scanf("%d%d", &n, &c) != EOF){
        int count = 0;
        for(int i=0; i<primeIndex; i++){
            if(primeTable[i] > n){
                count = i;
                break;
            }
        }
        printf("%d %d:", n, c);
        if(count % 2){
            if(2 * c - 1 <= count){
                for(int i=1, j=count/2-(c-1); i<=2*c-1; i++, j++)
                    printf(" %d", primeTable[j]);
            }
            else{
                for(int i=0; i<count; i++)
                    printf(" %d", primeTable[i]);
            }
        }
        else{
            if(2 * c <= count){
                for(int i=1, j=count/2-c; i<=2*c; i++, j++)
                    printf(" %d", primeTable[j]);
            }
            else{
                for(int i=0; i<count; i++)
                    printf(" %d", primeTable[i]);
            }
        }
        printf("\n\n");
    }
    return 0;
}


