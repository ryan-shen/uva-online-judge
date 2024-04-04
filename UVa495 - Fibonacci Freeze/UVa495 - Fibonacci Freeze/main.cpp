#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, fib[5001][1050];
    memset(fib, 0, sizeof(fib));
    fib[1][0] = 1;
    fib[2][0] = 1;
    for(int i=3; i<=5000; i++){
        for(int j=0; j<1050; j++){
            fib[i][j] += fib[i - 1][j] + fib[i - 2][j];
            fib[i][j + 1] += fib[i][j] / 10;
            fib[i][j] %= 10;
        }
    }
    while(scanf("%d", &n) != EOF){
        printf("The Fibonacci number for %d is ", n);
        if(n == 0){
            printf("0\n");
            continue;
        }
        bool lead = false;
        for(int i=1049; i>=0; i--){
            if(fib[n][i])
                lead = true;
            if(lead)
                printf("%d", fib[n][i]);
        }
        printf("\n");
    }
    return 0;
}


