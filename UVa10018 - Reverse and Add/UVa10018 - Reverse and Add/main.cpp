#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
long long reverse(long long n){
    long long r = 0;
    while(n > 0){
        r *= 10;
        r += n % 10;
        n /= 10;
    }
    return r;
}
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    while(test--){
        long long n;
        scanf("%lld", &n);
        int count = 0;
        do{
            n += reverse(n);
            count++;
        }while(n != reverse(n));
        printf("%d %lld\n", count, n);
    }
    return 0;
}

