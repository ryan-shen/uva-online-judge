#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
int maxDist = 100000;
using namespace std;
int n, goal, t, m;
int adj[101][101];
bool visited[101];
void Dijkstra(){
    memset(visited, false, sizeof(visited));
    for(int i=1; i<=n; i++){
        int minPoint = -1;
        int minValue = maxDist;
        for(int j=1; j<=n; j++){
            if(adj[goal][j] < minValue && !visited[j]){
                minPoint = j;
                minValue = adj[goal][j];
            }
        }
        if(minPoint == -1)
            return;
        visited[minPoint] = true;
        for(int j=1; j<=n; j++){
            adj[goal][j] = min(adj[goal][j], adj[goal][minPoint] + adj[minPoint][j]);
        }
    }
}
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        if(k > 1) printf("\n");
        scanf("%d%d%d%d", &n, &goal, &t, &m);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                adj[i][j] = maxDist;
            }
            adj[i][i] = 0;
        }
        for(int i=0; i<m; i++){
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            adj[b][a] = w;
        }
        int sum = 0;
        Dijkstra();
        for(int i=1; i<=n; i++)
            if(adj[goal][i] <= t)
                sum++;
        printf("%d\n", sum);
    }
    return 0;
}
