#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int parent[300005];
class Edge{
public:
    int from;
    int to;
    long long weight;
};
bool cmp(Edge a, Edge b){
    return a.weight < b.weight;
}
int FindParent(int x){
    while(parent[x] >= 0)
        x = parent[x];
    return x;
}
int main(int argc, const char * argv[]) {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0)){
        Edge edge[m];
        for(int i=0; i<n; i++)
            parent[i] = -1;
        for(int i=0; i<m; i++)
            scanf("%d%d%lld", &edge[i].from, &edge[i].to, &edge[i].weight);
        sort(edge, edge+m, cmp);
        long long cost = 0;
        for(int i=0; i<m; i++){
            if(FindParent(edge[i].from) != FindParent(edge[i].to)){
                if(parent[FindParent(edge[i].from)] < parent[FindParent(edge[i].to)]){
                    parent[FindParent(edge[i].from)] += parent[FindParent(edge[i].to)];
                    parent[FindParent(edge[i].to)] = FindParent(edge[i].from);
                }
                else{
                    parent[FindParent(edge[i].to)] += parent[FindParent(edge[i].from)];
                    parent[FindParent(edge[i].from)] = FindParent(edge[i].to);
                }
            }
            else
                cost += edge[i].weight;
        }
        printf("%lld\n", cost);
    }
    return 0;
}

