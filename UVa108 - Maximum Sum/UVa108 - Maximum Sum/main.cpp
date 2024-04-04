#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d", &n) != EOF) {
        int arr[n+1][n+1];
        int sum[n+1][n+1];
        int maxValue = -10000000;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        //清空邊界
        for(int i=0; i<=n; i++){
            sum[i][0] = 0;
            sum[0][i] = 0;
        }
        //sum[i][j] 為 sum[0][0] 加到 sum[i][j] 的值
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                sum[i][j] = 0;
                for(int x=1; x<=i; x++){
                    for(int y=1; y<=j; y++){
                        sum[i][j] += arr[x][y];
                    }
                }
            }
        }
        //i j 為長方形長寬
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                //x y 為長方形位置
                for(int x=n; x>=i; x--){
                    for(int y=n; y>=j; y--){
                        maxValue = max(maxValue, sum[x][y] + sum[x-i][y-j] - sum[x-i][y] - sum[x][y-j]);
                    }
                }
            }
        }
        printf("%d\n", maxValue);
    }
    return 0;
}

