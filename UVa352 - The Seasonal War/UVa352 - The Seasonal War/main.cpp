#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
char arr[30][30];
int cnt, n;
void clear(int r, int c){
    arr[r][c] = '0';
    if(r - 1 >= 0 && c - 1 >= 0){
        if(arr[r - 1][c - 1] == '1')
            clear(r - 1, c - 1);
    }
    if(r - 1 >= 0){
        if(arr[r - 1][c] == '1')
            clear(r - 1, c);
    }
    if(r - 1 >= 0 && c + 1 < n){
        if(arr[r - 1][c + 1] == '1')
            clear(r - 1, c + 1);
    }
    if(c + 1 < n){
        if(arr[r][c + 1] == '1')
            clear(r, c + 1);
    }
    if(r + 1 < n && c + 1 < n){
        if(arr[r + 1][c + 1] == '1')
            clear(r + 1, c + 1);
    }
    if(r + 1 < n){
        if(arr[r + 1][c] == '1')
            clear(r + 1, c);
    }
    if(r + 1 < n && c - 1 >= 0){
        if(arr[r + 1][c - 1] == '1')
            clear(r + 1, c - 1);
    }
    if(c - 1 >= 0){
        if(arr[r][c - 1] == '1')
            clear(r, c - 1);
    }
}
bool check(int row, int col){
    if(arr[row][col] == '1'){
        clear(row, col);
        return true;
    }
    else
        return false;
}
int main(int argc, const char * argv[]) {
    int test = 1;
    while(scanf("%d", &n) != EOF){
        for(int i=0; i<n; i++)
            scanf("%s", arr[i]);
        cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(check(i, j))
                    cnt++;
            }
        }
        printf("Image number %d contains %d war eagles.\n", test++, cnt);
    }
    return 0;
}


