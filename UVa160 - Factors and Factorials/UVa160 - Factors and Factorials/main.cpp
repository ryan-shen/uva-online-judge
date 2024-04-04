#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int arr[101];
int n;
bool isPrime(int x){
    for(int i=2; i<=sqrt(x); i++){
        if(x % i == 0)
            return false;
    }
    return true;
}
void factor(int x){
    int i = 2;
    while(x > 1){
        if(x % i == 0){
            arr[i]++;
            x /= i;
        }
        else
            i++;
    }
}
int main(int argc, const char * argv[]) {
    while (scanf("%d", &n) != EOF && n != 0) {
        memset(arr, 0, sizeof(arr));
        for(int i=2; i<=n; i++)
            factor(i);
        printf("%3d! =", n);
        int count = 0;
        for(int i=2; i<=n; i++){
            if(isPrime(i)){
                if(count == 15){
                    count = 0;
                    printf("\n      ");
                }
                printf("%3d", arr[i]);
                count++;
            }
        }
        printf("\n");
    }
    return 0;
}

