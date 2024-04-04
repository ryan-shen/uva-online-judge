#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    for(int k=0; k<test; k++){
        if(k)
            printf("\n");
        int n;
        scanf("%d", &n);
        int a[n], b[n], sum[n];
        for(int i=0; i<n; i++){
            scanf("%d%d", &a[i], &b[i]);
            sum[i] = 0;
        }
        int lead = 0;
        for(int i=n-1; i>=0; i--){
            sum[i] += a[i] + b[i];
            if(sum[i] >= 10){
                sum[i] -= 10;
                if(i > 0)
                    sum[i-1]++;
                else
                    lead++;
            }
        }
        if(lead)
            printf("%d", lead);
        for(int i=0; i<n; i++)
            printf("%d", sum[i]);
        printf("\n");
    }
    return 0;
}

