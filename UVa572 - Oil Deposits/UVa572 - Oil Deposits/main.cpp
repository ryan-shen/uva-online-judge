#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
char arr[105][105];
int cnt, n, m;
void clear(int r, int c){
    arr[r][c] = '*';
    if(r - 1 >= 0 && c - 1 >= 0){
        if(arr[r - 1][c - 1] == '@')
            clear(r - 1, c - 1);
    }
    if(r - 1 >= 0){
        if(arr[r - 1][c] == '@')
            clear(r - 1, c);
    }
    if(r - 1 >= 0 && c + 1 < n){
        if(arr[r - 1][c + 1] == '@')
            clear(r - 1, c + 1);
    }
    if(c + 1 < n){
        if(arr[r][c + 1] == '@')
            clear(r, c + 1);
    }
    if(r + 1 < m && c + 1 < n){
        if(arr[r + 1][c + 1] == '@')
            clear(r + 1, c + 1);
    }
    if(r + 1 < m){
        if(arr[r + 1][c] == '@')
            clear(r + 1, c);
    }
    if(r + 1 < m && c - 1 >= 0){
        if(arr[r + 1][c - 1] == '@')
            clear(r + 1, c - 1);
    }
    if(c - 1 >= 0){
        if(arr[r][c - 1] == '@')
            clear(r, c - 1);
    }
}
bool check(int row, int col){
    if(arr[row][col] == '@'){
        clear(row, col);
        return true;
    }
    else
        return false;
}
int main(int argc, const char * argv[]) {
    while(scanf("%d%d", &m, &n) != EOF && !(m == 0 && n == 0)){
        for(int i=0; i<m; i++)
            scanf("%s", arr[i]);
        cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(check(i, j))
                    cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}


