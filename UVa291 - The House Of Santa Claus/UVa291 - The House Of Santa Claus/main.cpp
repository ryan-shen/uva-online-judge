#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
bool arr[6][6];
bool visited[6][6];
int path[6];
void DFS(int now, int layer){
    path[layer] = now;
    for(int i=1; i<=5; i++){
        if(arr[now][i] && !visited[now][i]){
            visited[now][i] = visited[i][now] = true;
            DFS(i, layer + 1);
            visited[now][i] = visited[i][now] = false;
        }
        if(layer == 9){
            for(int j=1; j<=9; j++)
                printf("%d", path[j]);
            printf("\n");
            return;
        }
    }
}
int main(int argc, const char * argv[]) {
    arr[1][2] = arr[2][1] = true;
    arr[1][3] = arr[3][1] = true;
    arr[1][5] = arr[5][1] = true;
    arr[2][3] = arr[3][2] = true;
    arr[2][5] = arr[5][2] = true;
    arr[3][4] = arr[4][3] = true;
    arr[3][5] = arr[5][3] = true;
    arr[4][5] = arr[5][4] = true;
    DFS(1, 1);
    return 0;
}


