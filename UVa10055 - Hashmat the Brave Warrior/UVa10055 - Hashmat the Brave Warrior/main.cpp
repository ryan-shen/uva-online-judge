#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, const char * argv[]) {
    long long int n1, n2;
    while(scanf("%lld%lld", &n1, &n2) != EOF)
        printf("%lld\n", abs(n1 - n2));
    return 0;
}

