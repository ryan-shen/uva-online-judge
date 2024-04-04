#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int parent[30000];
int findParent(int x){
    while(parent[x] >= 0)
        x = parent[x];
    return x;
}
int main(int argc, const char * argv[]) {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0)){
        int group[30000];
        for(int i=0; i<n; i++)
            parent[i] = -1;
        for(int i=0; i<m; i++){
            int temp;
            scanf("%d", &temp);
            for(int j=0; j<temp; j++)
                scanf("%d", &group[j]);
            sort(group, group+temp);
            for(int j=1; j<temp; j++){
                int p1 = findParent(group[j - 1]);
                int p2 = findParent(group[j]);
                if(p1 > p2){
                    parent[p2] += parent[p1];
                    parent[p1] = p2;
                }
                else if(p1 < p2){
                    parent[p1] += parent[p2];
                    parent[p2] = p1;
                }
            }
        }
        printf("%d\n", -parent[0]);
    }
    return 0;
}


