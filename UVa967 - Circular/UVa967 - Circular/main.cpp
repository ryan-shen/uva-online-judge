#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int maxN = 1000001;
    bool primeTable[maxN];
    memset(primeTable, true, sizeof(primeTable));
    primeTable[0] = primeTable[1] = false;
    for(int i=2; i<maxN; i++){
        if(primeTable[i]){
            for(int j=i+i; j<maxN; j+=i)
                primeTable[j] = false;
        }
    }
    
    int circularPrime[45];
    int circularIndex = 0;
    for(int i=100; i<maxN; i++){
        int n = i;
        int digit = 0;
        bool pass = true;
        while(n > 0){
            digit++;
            n /= 10;
        }
        n = i;
        for(int j=0; j<digit; j++){
            if(!primeTable[n]){
                pass = false;
                break;
            }
            int temp = n % 10;
            n /= 10;
            n += temp * pow(10, digit - 1);
        }
        if(pass)
            circularPrime[circularIndex++] = i;
    }
    
    int a, b;
    while(scanf("%d", &a) != EOF && a != -1){
        scanf("%d", &b);
        int count = 0;
        for(int i=0; i<circularIndex; i++){
            if(circularPrime[i] >= a){
                if(circularPrime[i] <= b)
                    count++;
                else
                    break;
            }
        }
        if(count > 1)
            printf("%d Circular Primes.\n", count);
        else if(count)
            printf("%d Circular Prime.\n", count);
        else
            printf("No Circular Primes.\n");
    }
    return 0;
}


