#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int fib[40], maxIndex = 0;
    fib[0] = 1;
    fib[1] = 2;
    for(int i=2; ; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        if(fib[i]>100000000){
            maxIndex = i;
            break;
        }
    }
    int test, n;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        printf("%d = ", n);
        bool lead = false;
        for(int i=maxIndex-1; i>=0; i--){
            if(n - fib[i] >= 0){
                n -= fib[i];
                printf("1");
                lead = true;
            }
            else if(lead){
                printf("0");
            }
        }
        printf(" (fib)\n");
    }
    return 0;
}
