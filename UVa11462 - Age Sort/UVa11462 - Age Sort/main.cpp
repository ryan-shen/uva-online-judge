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
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+n);
        printf("%d", arr[0]);
        for(int i=1; i<n; i++)
            printf(" %d", arr[i]);
        printf("\n");
    }
    return 0;
}

