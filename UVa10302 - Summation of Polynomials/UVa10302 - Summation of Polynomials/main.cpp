#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    long long n;
    while(scanf("%lld", &n) != EOF){
        printf("%lld\n", n * n * (n+1) * (n+1) / 4);
    }
    return 0;
}

