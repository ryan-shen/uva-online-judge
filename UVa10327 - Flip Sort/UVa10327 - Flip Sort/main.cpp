#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF){
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        int sum = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<i; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    sum++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", sum);
    }
    return 0;
}

