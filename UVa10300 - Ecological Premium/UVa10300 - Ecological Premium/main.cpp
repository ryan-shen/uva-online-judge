#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);
        long long space[n], animal[n], friendliness[n];
        for(int i=0; i<n; i++)
            scanf("%lld%lld%lld", &space[i], &animal[i], &friendliness[i]);
        long long sum = 0;
        for(int i=0; i<n; i++)
            sum += space[i] * friendliness[i];
        printf("%lld\n", sum);
    }
    return 0;
}

