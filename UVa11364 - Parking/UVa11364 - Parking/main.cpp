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
    while(test--){
        scanf("%d", &n);
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+n);
        printf("%d\n", (arr[n - 1] - arr[0]) * 2);
    }
    return 0;
}


