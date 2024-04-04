#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int sum1, sum2;
void addToSum(int n){
    for(int i=0; i<2; i++){
        sum2 += n % 10;
        n /= 10;
        int temp = n % 10;
        sum1 += temp * 2 / 10 + temp * 2 % 10;
        n /= 10;
    }
}
int main(int argc, const char * argv[]) {
    int test, a, b, c, d;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        sum1 = 0;
        sum2 = 0;
        addToSum(a);
        addToSum(b);
        addToSum(c);
        addToSum(d);
        printf("%s\n", (sum1 + sum2) % 10 == 0 ? "Valid" : "Invalid");
    }
    return 0;
}

