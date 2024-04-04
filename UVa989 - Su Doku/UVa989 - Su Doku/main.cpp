#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int arr[9][9], n;
bool isChangeable[9][9], pass;
bool check(int row, int col){
    for(int i=0; i<n; i++){
        if(i == col)
            continue;
        if(arr[row][i] == arr[row][col])
            return false;
    }
    for(int i=0; i<n; i++){
        if(i == row)
            continue;
        if(arr[i][col] == arr[row][col])
            return false;
    }
    int block = sqrt(n);
    int gridR = row / block;
    int gridC = col / block;
    for(int i=gridR*block; i<gridR*block+block; i++){
        for(int j=gridC*block; j<gridC*block+block; j++){
            if(i == row && j == col)
                continue;
            if(arr[i][j] == arr[row][col])
                return false;
        }
    }
    return true;
}
void DFS(int row, int col){
    if(!pass){
        if(isChangeable[row][col]){
            for(int i=1; i<=n; i++){
                arr[row][col] = i;
                if(check(row, col)){
                    if(col < n - 1)
                        DFS(row, col + 1);
                    else if(row < n - 1)
                        DFS(row + 1, 0);
                    else
                        pass = true;
                }
                if(pass) return;
            }
            arr[row][col] = 0;
        }
        else if(col < n - 1)
            DFS(row, col + 1);
        else if(row < n - 1)
            DFS(row + 1, 0);
        else
            pass = true;
    }
}
int main(int argc, const char * argv[]) {
    int printLine = 0;
    while(scanf("%d", &n) != EOF){
        if(printLine++) printf("\n");
        n *= n;
        pass = false;
        memset(isChangeable, false, sizeof(isChangeable));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &arr[i][j]);
                if(!arr[i][j]){
                    isChangeable[i][j] = true;
                }
            }
        }
        DFS(0, 0);
        if(pass){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(j)
                        printf(" ");
                    printf("%d", arr[i][j]);
                }
                printf("\n");
            }
        }
        else
            printf("NO SOLUTION\n");
    }
    return 0;
}


