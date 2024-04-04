#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, test = 1;
    while(scanf("%d", &n) != EOF && n != 0){
        int arr[n][n];
        int count = n / 2 + n % 2;
        int sum[count + 1];
        memset(sum, 0, sizeof(sum));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d", &arr[i][j]);
        
        for(int k=0; k<count; k++){
            for(int i=k; i<n-k; i++){
                for(int j=k; j<n-k; j++){
                    sum[k] += arr[i][j];
                }
            }
        }
        //外圈減內圈
        printf("Case %d:", test++);
        for(int i=0; i<count; i++)
            printf(" %d", sum[i] - sum[i + 1]);
        printf("\n");
    }
    return 0;
}

