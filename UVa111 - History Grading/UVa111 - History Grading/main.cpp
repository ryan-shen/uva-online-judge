#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int n;
void arrangeOrder(int arr[]){
    //要重新排列事件順序，因為測資給的是時間順序
    int temp[n+1];
    for(int i=1; i<=n; i++){
        temp[arr[i]] = i;
    }
    for(int i=1; i<=n; i++){
        arr[i] = temp[i];
    }
}
int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    int answer[n+1];
    int response[n+1];
    for(int i=1; i<=n; i++)
        scanf("%d", &answer[i]);
    arrangeOrder(answer);
    while (scanf("%d", &response[1]) != EOF) {
        for(int i=2; i<=n; i++)
            scanf("%d", &response[i]);
        arrangeOrder(response);
        int lcs[n+1][n+1];
        for(int i=0; i<=n; i++){
            lcs[i][0] = 0;
            lcs[0][i] = 0;
        }
        //用 DP 找出最長共同子序列 (LCS)
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(response[i] == answer[j])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
        printf("%d\n", lcs[n][n]);
    }
    return 0;
}

