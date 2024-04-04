#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int parent[1000005];
class Side{
public:
    int v1;
    int v2;
    int weight;
    Side(){};
    Side(int a, int b, int c): v1(a), v2(b), weight(c){};
};
bool cmp(Side a, Side b){
    return a.weight < b.weight;
}
int findParent(int x){
    while(parent[x] > 0)
        x = parent[x];
    return x;
}
int main(int argc, const char * argv[]) {
    int n, m, k, printLine = 0;
    while(scanf("%d", &n) != EOF){
        if(printLine++) printf("\n");
        int oldSum = 0, newSum = 0;
        for(int i=0; i<n-1; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            oldSum += c;
        }
        scanf("%d", &k);
        Side tempSide[k];
        for(int i=0; i<k; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            tempSide[i] = Side(a, b, c);
        }
        scanf("%d", &m);
        Side side[k + m];
        for(int i=0; i<k; i++)
            side[i] = tempSide[i];
        for(int i=k; i<k+m; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            side[i] = Side(a, b, c);
        }
        sort(side, side+k+m, cmp);
        for(int i=1; i<=n; i++)
            parent[i] = -1;
        for(int i=0; i<k+m; i++){
            int p1 = findParent(side[i].v1);
            int p2 = findParent(side[i].v2);
            if(p1 != p2){
                if(parent[p1] <= parent[p2]){
                    parent[p1] += parent[p2];
                    parent[p2] = p1;
                }
                else{
                    parent[p2] += parent[p1];
                    parent[p1] = p2;
                }
                newSum += side[i].weight;
            }
        }
        printf("%d\n%d\n", oldSum, newSum);
    }
    return 0;
}


