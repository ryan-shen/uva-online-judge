#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, q, test = 1;
    while(scanf("%d%d", &n, &q) != EOF && !(n == 0 && q == 0)){
        int arr[n];
        printf("CASE# %d:\n", test++);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+n);
        for(int i=0; i<q; i++){
            int qq;
            scanf("%d", &qq);
            for(int j=0; j<n; j++){
                if(arr[j] == qq){
                    printf("%d found at %d\n", qq, j + 1);
                    break;
                }
                else if(j == n - 1)
                    printf("%d not found\n", qq);
            }
        }
    }
    return 0;
}


