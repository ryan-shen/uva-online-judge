#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d", &n) != EOF && n != 0){
        int sum = 0;
        for(int i=1; i<n; i++)
            if(n % i == 0)
                sum += i;
        
        if(sum == n)
            printf("%5d  PERFECT\n", n);
        else if(sum > n)
            printf("%5d  ABUNDANT\n", n);
        else
            printf("%5d  DEFICIENT\n", n);
    }
    printf("END OF OUTPUT\n");
    return 0;
}


