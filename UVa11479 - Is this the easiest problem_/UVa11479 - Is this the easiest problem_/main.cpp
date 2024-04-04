#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    long long a, b, c;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a + b > c && b + c > a && a + c > b && a > 0 && b > 0 && c > 0){
            if(a == b && b == c)
                printf("Case %d: Equilateral\n", k);
            else if(a == b || b == c || a == c)
                printf("Case %d: Isosceles\n", k);
            else
                printf("Case %d: Scalene\n", k);
        }
        else
            printf("Case %d: Invalid\n", k);
    }
    return 0;
}

