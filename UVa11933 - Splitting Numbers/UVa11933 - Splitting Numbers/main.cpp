#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    long long n;
    while(scanf("%lld", &n) != EOF && n != 0){
        long long bit = 1;
        long long answer[2] = {0};
        int addTo = 1;
        while(bit <= n){
            if(n & bit)
                answer[addTo ^= 1] += bit;
            bit <<= 1;
        }
        printf("%lld %lld\n", answer[0], answer[1]);
    }
    return 0;
}

