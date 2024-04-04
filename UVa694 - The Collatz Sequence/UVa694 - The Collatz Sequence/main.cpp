#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    long long n, limit;
    int test = 1;
    while(scanf("%lld%lld", &n, &limit) != EOF && !(n < 0 && limit < 0)){
        int count = 0;
        printf("Case %d: A = %lld, limit = %lld, number of terms = ", test++, n, limit);
        while(n > 1 && n <= limit){
            count++;
            if(n % 2)
                n = n * 3 + 1;
            else
                n /= 2;
        }
        printf("%d\n", n == 1 ? count + 1 : count);
    }
    return 0;
}


