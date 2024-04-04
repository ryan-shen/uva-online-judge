#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
int n, maxN = 1000000, test = 1;
int start, goal, side, adj[101][101];
int bottleNeck[101];    //到節點 n 為止的瓶頸流量
int parent[101];        //找路徑用，紀錄從哪個節點來
bool visited[101];
int BFS(){
    //找出一條通往終點的路徑，並紀錄瓶頸流量
    for(int i=1; i<=n; i++){
        visited[i] = false;
        bottleNeck[i] = maxN;
    }
    visited[start] = true;
    parent[start] = -1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if(adj[now][i] && !visited[i]){
                visited[i] = true;
                parent[i] = now;
                bottleNeck[i] = min(bottleNeck[now], adj[now][i]);
                q.push(i);
                if(i == goal)
                    return bottleNeck[i];
            }
        }
    }
    return 0;
}
int EdmondsKarp(){
    int maxFlow = 0, flow;
    
    //最大流由許多小流加總而成
    while((flow = BFS())){
        maxFlow += flow;
        
        //更新剩餘網路
        int x = goal;
        while(parent[x] > 0){
            adj[x][parent[x]] += flow;
            adj[parent[x]][x] -= flow;
            x = parent[x];
        }
    }
    return maxFlow;
}
int main(int argc, const char * argv[]) {
    while(scanf("%d", &n) != EOF && n != 0){
        scanf("%d%d%d", &start, &goal, &side);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                adj[i][j] = 0;
            }
        }
        for(int i=0; i<side; i++){
            int v1, v2, w;
            scanf("%d%d%d", &v1, &v2, &w);
            adj[v1][v2] += w;
            adj[v2][v1] += w;
        }
        
        printf("Network %d\n", test++);
        printf("The bandwidth is %d.\n\n", EdmondsKarp());
    }
    return 0;
}


