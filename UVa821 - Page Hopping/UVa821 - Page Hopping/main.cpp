#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test = 1, from, to, maxDist = 10000, maxN = 101;
    int adj[101][101];
    for(int i=1; i<maxN; i++){
        for(int j=1; j<maxN; j++){
            adj[i][j] = maxDist;
        }
    }
    while(scanf("%d%d", &from, &to) != EOF){
        if(!from && !to){
            for(int k=1; k<maxN; k++){
                for(int i=1; i<maxN; i++){
                    for(int j=1; j<maxN; j++){
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
            int total = 0;
            int count = 0;
            for(int i=1; i<maxN; i++){
                for(int j=1; j<maxN; j++){
                    if(i == j)
                        continue;
                    if(adj[i][j] < maxN){
                        total += adj[i][j];
                        count++;
                    }
                }
            }
            printf("Case %d: average length between pages = %.3lf clicks\n", test++, total * 1.0 / count);
            for(int i=1; i<maxN; i++){
                for(int j=1; j<maxN; j++){
                    adj[i][j] = maxDist;
                }
            }
            scanf("%d%d", &from, &to);
            if(!from && !to) break;
        }
        adj[from][to] = 1;
    }
    return 0;
}


