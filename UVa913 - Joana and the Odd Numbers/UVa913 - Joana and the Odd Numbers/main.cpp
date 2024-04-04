#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF){
        long long line = n / 2 + 1;
        long long num = line * line * 2 + 1;
        printf("%lld\n", (num - 2) + (num - 4) + (num - 6));
    }
    return 0;
}


