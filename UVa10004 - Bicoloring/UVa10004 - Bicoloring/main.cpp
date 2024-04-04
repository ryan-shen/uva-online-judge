#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
bool adj[200][200];
int color[200];
bool pass;
int n, m;
bool visited[200];
void DFS(int now){
    for(int i=0; i<n; i++){
        if(adj[now][i]){
            if(color[i] == -1)
                color[i] = color[now] ^ 1;
            else if(color[i] == color[now]){
                pass = false;
                return;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(adj[now][i] && !visited[i]){
            visited[i] = true;
            DFS(i);
            visited[i] = false;
        }
    }
}
int main(int argc, const char * argv[]) {
    while(scanf("%d", &n) != EOF && n != 0){
        scanf("%d", &m);
        memset(adj, false, sizeof(adj));
        memset(visited, false, sizeof(visited));
        memset(color, -1, sizeof(color));
        for(int i=0; i<m; i++){
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            adj[v1][v2] = true;
            adj[v2][v1] = true;
        }
        pass = true;
        color[0] = 0;
        visited[0] = true;
        DFS(0);
        if(pass)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
            
    }
    return 0;
}

