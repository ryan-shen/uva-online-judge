#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    vector<int> twinPrime;
    vector<bool> isPrime(18500000, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2; i<18500000; i++){
        if(isPrime[i]){
            for(int j=i+i; j<18500000; j+=i){
                isPrime[j] = false;
            }
            if(isPrime[i - 2])
                twinPrime.push_back(i - 2);
        }
    }
    while(scanf("%d", &n) != EOF)
        printf("(%d, %d)\n", twinPrime[n - 1], twinPrime[n - 1] + 2);
    return 0;
}

