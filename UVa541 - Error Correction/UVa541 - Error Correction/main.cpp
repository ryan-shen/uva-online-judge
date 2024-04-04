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
        int arr[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        
        bool ok = true;
        int corruptRow = 0, corruptCol = 0, r = 0, c = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=0; j<n; j++){
                sum += arr[i][j];
            }
            if(sum % 2){
                ok = false;
                corruptRow++;
                r = i;
            }
            sum = 0;
            for(int j=0; j<n; j++){
                sum += arr[j][i];
            }
            if(sum % 2){
                ok = false;
                corruptCol++;
                c = i;
            }
        }
        if(ok)
            printf("OK\n");
        else if(corruptRow > 1 || corruptCol > 1)
            printf("Corrupt\n");
        else
            printf("Change bit (%d,%d)\n", r + 1, c + 1);
    }
    return 0;
}


