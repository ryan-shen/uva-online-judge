#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    long long gcd, lcm;
    scanf("%d", &test);
    while(test--){
        scanf("%lld%lld", &gcd, &lcm);
        if(lcm % gcd == 0)
            printf("%lld %lld\n", gcd, lcm);
        else
            printf("-1\n");
    }
    return 0;
}

