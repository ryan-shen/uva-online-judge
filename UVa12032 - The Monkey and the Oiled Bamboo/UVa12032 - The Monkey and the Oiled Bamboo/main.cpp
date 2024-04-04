#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d", &n);
        int arr[n + 1];
        int maxValue;
        arr[0] = 0;
        for(int i=1; i<=n; i++)
            scanf("%d", &arr[i]);
        
        maxValue = arr[n] - arr[n - 1];
        for(int i=n-1; i>0; i--){
            if(maxValue < arr[i] - arr[i - 1])
                maxValue = arr[i] - arr[i - 1];
            else if(maxValue == arr[i] - arr[i - 1])
                maxValue = arr[i] - arr[i - 1] + 1;
        }
        printf("Case %d: %d\n", k, maxValue);
    }
    return 0;
}
