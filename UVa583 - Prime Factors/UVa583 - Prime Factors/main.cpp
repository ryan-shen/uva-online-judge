#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        printf("%d = ", n);
        bool lead = false, prime = true;
        if(n < 0){
            printf("-1");
            lead = true;
            n *= -1;
        }
        for(int i=2; i<=n; i++){
            if(i > sqrt(n) && prime)
                break;
            while(n % i == 0){
                prime = false;
                if(!lead){
                    printf("%d", i);
                    lead = true;
                }
                else
                    printf(" x %d", i);
                n /= i;
            }
        }
        if(lead && !prime)
            printf("\n");
        else if(lead && prime)
            printf(" x %d\n", n);
        else
            printf("%d\n", n);
    }
    return 0;
}


