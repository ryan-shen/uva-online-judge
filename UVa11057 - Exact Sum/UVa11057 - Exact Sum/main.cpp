#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, money;
bool cmp(int a, int b){
    return a < b;
}
int main(int argc, const char * argv[]) {
    while(scanf("%d", &n) != EOF){
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+n, cmp);
        scanf("%d", &money);
        int a, b;
        for(int i=0; i<n; i++){
            if(arr[i] > money / 2)
                break;
            for(int j=n-1; j>i; j--){
                if(arr[j] < money / 2)
                    break;
                if(arr[i] + arr[j] == money){
                    a = arr[i];
                    b = arr[j];
                    break;
                }
            }
        }
        
        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }
    return 0;
}

