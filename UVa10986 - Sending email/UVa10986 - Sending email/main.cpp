#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
class Node{
public:
    int to;
    int weight;
    Node(){};
    Node(int a, int b): to(a), weight(b){};
};
bool cmp(Node a, Node b){
    return a.weight > b.weight;
}
int main(int argc, const char * argv[]) {
    int n, m, start, end, maxN = 100000, test;
    scanf("%d", &test);
    for(int l=1; l<=test; l++){
        scanf("%d%d%d%d", &n, &m, &start, &end);
        int adj[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j] = maxN;
            }
            adj[i][i] = 0;
        }
        for(int i=0; i<m; i++){
            int v1, v2, weight;
            scanf("%d%d%d", &v1, &v2, &weight);
            adj[v1][v2] = min(adj[v1][v2], weight);
            adj[v2][v1] = min(adj[v2][v1], weight);
        }
        
        priority_queue<Node, vector<Node>, function<bool(Node, Node)>> pq(cmp);
        for(int i=0; i<n; i++)
            pq.push(Node(i, adj[start][i]));
        bool visited[n];
        memset(visited, false, sizeof(visited));
        visited[start] = true;
        while(true){
            Node minPoint = pq.top();
            pq.pop();
            if(minPoint.to == end)
                break;
            else if(visited[minPoint.to])
                continue;
            visited[minPoint.to] = true;
            for(int j=0; j<n; j++){
                if(adj[start][j] > adj[start][minPoint.to] + adj[minPoint.to][j]){
                    adj[start][j] = adj[start][minPoint.to] + adj[minPoint.to][j];
                    pq.push(Node(j, adj[start][j]));
                }
            }
        }
        
        if(adj[start][end] != maxN)
            printf("Case #%d: %d\n", l, adj[start][end]);
        else
            printf("Case #%d: unreachable\n", l);
    }
    return 0;
}

