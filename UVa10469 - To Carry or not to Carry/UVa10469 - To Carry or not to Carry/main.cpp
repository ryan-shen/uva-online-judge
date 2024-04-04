#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    long long a, b;
    while(scanf("%lld%lld", &a, &b) != EOF)
        printf("%lld\n", a ^ b);
    return 0;
}

