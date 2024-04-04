#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    long long n, m;
    int year;
    while(scanf("%d", &year) != EOF && year != -1){
        m = 0;
        n = 1;
        for(int i=1; i<=year; i++){
            long long tempN = n;
            long long tempM = m;
            m += tempN;
            n = tempM + 1;
        }
        printf("%lld %lld\n", m, m + n);
    }
    return 0;
}

