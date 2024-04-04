#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    long long n;
    scanf("%d", &test);
    while(test--){
        scanf("%lld", &n);
        n = (-1 + sqrt(1 + 8 * n)) / 2;
        printf("%lld\n", n);
    }
    return 0;
}

