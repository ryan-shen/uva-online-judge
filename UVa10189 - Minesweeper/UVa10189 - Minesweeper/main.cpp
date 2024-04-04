#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
char arr[101][101];
char answer[101][101];
int row, col;
void Mine(int r, int c){
    if(answer[r-1][c-1] != '*' && r && c)
        answer[r-1][c-1]++;
    if(answer[r-1][c] != '*' && r)
        answer[r-1][c]++;
    if(answer[r-1][c+1] != '*' && r && c < col)
        answer[r-1][c+1]++;
    if(answer[r][c+1] != '*' && c < col)
        answer[r][c+1]++;
    if(answer[r+1][c+1] != '*' && r < row && c < col)
        answer[r+1][c+1]++;
    if(answer[r+1][c] != '*' && r < row)
        answer[r+1][c]++;
    if(answer[r+1][c-1] != '*' && r < row && c)
        answer[r+1][c-1]++;
    if(answer[r][c-1] != '*' && c)
        answer[r][c-1]++;
}
int main(int argc, const char * argv[]) {
    int printLine = 0;
    while(scanf("%d%d", &row, &col) != EOF && row && col){
        if(printLine++)
            printf("\n");
        cin.getline(arr[0], 101); //吃掉前面的換行符號
        for(int i=0; i<row; i++)
            cin.getline(arr[i], 101);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(arr[i][j] == '*')
                    answer[i][j] = '*';
                else
                    answer[i][j] = '0';
            }
        }
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(arr[i][j] == '*')
                    Mine(i, j);
            }
        }
        printf("Field #%d:\n", printLine);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                printf("%c", answer[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

