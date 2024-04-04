#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    while(test--){
        int arr[501];
        int n;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        int sum = 0;
        sort(arr, arr+n);
        int mid = n / 2;
        for(int i=0; i<n; i++){
            sum += abs(arr[mid] - arr[i]);
        }
        printf("%d\n", sum);
    }
    return 0;
}

