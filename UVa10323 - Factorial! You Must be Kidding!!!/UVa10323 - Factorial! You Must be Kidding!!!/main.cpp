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
        if(n < 0){
            if(n % 2)
                printf("Overflow!\n");
            else
                printf("Underflow!\n");
        }
        else{
            long long factorial = 1;
            for(int i=2; i<=n; i++){
                factorial *= i;
                if(factorial > 6227020800){
                    printf("Overflow!\n");
                    break;
                }
            }
            if(factorial < 10000)
                printf("Underflow!\n");
            else if(factorial <= 6227020800)
                printf("%lld\n", factorial);
        }
    }
    return 0;
}

