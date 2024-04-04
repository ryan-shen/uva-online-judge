#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int p[100][100];
int box[100][100];
int dimension;
void path(int x, int y){
    if(p[x][y] != -1){
        path(x, p[x][y]);
        printf(" %d", p[x][y] + 1);
        path(p[x][y], y);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d%d", &n, &dimension) != EOF){
        for(int i=0; i<n; i++){
            for(int j=0; j<dimension; j++){
                scanf("%d", &box[i][j]);
            }
        }
        for(int i=0; i<n; i++)
            sort(box[i], box[i]+dimension);
        int adj[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j] = 100000000;
            }
        }
        //計算箱子 i 可否被箱子 j 包覆
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<dimension; k++){
                    if(k == dimension-1 && box[i][k] < box[j][k])
                        adj[i][j] = -1;
                    else if(box[i][k] >= box[j][k])
                        break;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
        //計算最長路徑，限有向無環圖 (DAG)
        memset(p, -1, sizeof(p));
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(adj[i][j] > adj[i][k] + adj[k][j]){
                        adj[i][j] = adj[i][k] + adj[k][j];
                        p[i][j] = k;
                    }
                }
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cout << adj[i][j] << " ";
                }
                cout << endl;
            }
        }
        
        //找出最內部的箱子，並一層一層往外找
        int maxValue = 0;
        int start = 0;
        int end = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(maxValue > adj[i][j]){
                    maxValue = adj[i][j];
                    start = i;
                    end = j;
                }
            }
        }
        printf("%d\n", maxValue * -1 + 1);
        printf("%d", start + 1);
        path(start, end);
        if(start != end)
            printf(" %d\n", end + 1);
        else
            printf("\n");
        
    }
    return 0;
}
