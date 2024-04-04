#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test = 1, n;
    while(scanf("%d", &n) != EOF){
        long long arr[n];
        long long dpmax[n], dpmin[n];
        for(int i=0; i<n; i++)
            scanf("%lld", &arr[i]);
        dpmax[0] = arr[0];
        dpmin[0] = arr[0];
        for(int i=1; i<n; i++){
            long long a, b;
            if(dpmax[i - 1] < 1)
                a = arr[i];
            else
                a = arr[i] * dpmax[i - 1];
            b = arr[i] * dpmin[i - 1];
            dpmax[i] = max(a, b);
            dpmin[i] = min(a, b);
        }
        long long answer = 0;
        for(int i=0; i<n; i++)
            answer = max(answer, dpmax[i]);
        printf("Case #%d: The maximum product is %lld.\n\n", test++, answer);
    }
    return 0;
}

