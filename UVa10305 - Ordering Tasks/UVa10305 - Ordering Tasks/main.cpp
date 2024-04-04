#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0)){
        bool visited[n+1];
        bool adj[n+1][n+1];
        memset(visited, false, sizeof(visited));
        memset(adj, false, sizeof(adj));
        vector<int> vec;
        vec.clear();
        vec.push_back(0);
        auto it1 = vec.begin();
        auto it2 = vec.begin();
        for(int k=0; k<m; k++){
            int t1, t2;
            scanf("%d%d", &t1, &t2);
            adj[t1][t2] = true;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(adj[i][j]){
                    it1 = vec.begin();
                    it2 = vec.begin();
            
                    for(; it1 != vec.end(); it1++)
                        if(*it1 == i)
                            break;
                    for(; it2 != vec.end(); it2++)
                        if(*it2 == j)
                            break;
            
                    if(it1 == vec.end() && it2 == vec.end()){
                        vec.push_back(i);
                        vec.push_back(j);
                    }
                    else if(it2 == vec.end())
                        vec.push_back(j);
                    else if(it1 == vec.end())
                        vec.insert(it2, i);
                    else if(it2 < it1){
                        vec.erase(it2);
                        vec.insert(it1, j);
                    }
                    visited[i] = true;
                    visited[j] = true;
                }
            }
        }
        
        for(int i=1; i<=n; i++)
            if(!visited[i])
                vec.push_back(i);
        for(auto it = vec.begin(); it != vec.end(); it++){
            if(*it != 0){
                if(it == vec.end()-1)
                    printf("%d", *it);
                else
                    printf("%d ", *it);
            }
        }
        printf("\n");
    }
    return 0;
}

