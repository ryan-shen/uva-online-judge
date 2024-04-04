#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
long long func(long long x, long long y, long long n){
    if(y == 1)
        return x;
    if(y % 2)
        return func(x, y - 1, n) % n * x % n;
    else
        return func(x * x % n, y / 2, n);
}
int main(int argc, const char * argv[]) {
    long long x, y, n;
    int test;
    while(scanf("%d", &test) != EOF && test != 0){
    for(int k=1; k<=test; k++){
        scanf("%lld%lld%lld", &x, &y, &n);
        printf("%lld\n", func(x, y, n));
    }
    }
    return 0;
}
