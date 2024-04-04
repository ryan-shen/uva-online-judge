#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    long long n;
    while(scanf("%lld", &n) != EOF && n >= 0){
        long long sum = 1;
        sum += (1 + n) * n / 2;
        printf("%lld\n", sum);
    }
    return 0;
}

