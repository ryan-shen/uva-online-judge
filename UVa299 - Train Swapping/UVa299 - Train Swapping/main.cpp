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
    while (test--) {
        int n;
        scanf("%d", &n);
        int arr[n+1];
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        int count = 0;
        int now = 1;
        while (now < n) {
            for(int i=now+1; i<=n; i++){
                if(arr[i] == now){
                    for(int j=i; j>now; j--){
                        int temp = arr[j];
                        arr[j] = arr[j-1];
                        arr[j-1] = temp;
                        count++;
                    }
                    break;
                }
            }
            now++;
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    return 0;
}

