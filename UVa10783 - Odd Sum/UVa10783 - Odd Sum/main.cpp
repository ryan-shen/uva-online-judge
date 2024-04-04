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
    for(int k=1; k<=test; k++){
        int a, b, sum = 0;
        scanf("%d%d", &a, &b);
        if(a % 2 == 0)
            a++;
        if(b % 2 == 0)
            b--;
        sum = ((b - a) / 2 + 1) * (a + b) / 2;
        printf("Case %d: %d\n", k, sum);
    }
    return 0;
}

