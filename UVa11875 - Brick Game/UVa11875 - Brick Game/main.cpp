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
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+n);
        printf("Case %d: %d\n", k, arr[n / 2]);
    }
    return 0;
}

