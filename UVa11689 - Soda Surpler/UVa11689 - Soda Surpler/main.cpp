#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, a, b, cost;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d%d", &a, &b, &cost);
        int n = a + b;
        int sum = 0;
        while(n >= cost){
            sum += n / cost;
            n = n / cost + n % cost;
        }
        printf("%d\n", sum);
    }
    return 0;
}

