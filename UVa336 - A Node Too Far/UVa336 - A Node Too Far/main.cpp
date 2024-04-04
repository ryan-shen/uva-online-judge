#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, start, ttl, test = 1;
    while(scanf("%d", &n) != EOF && n != 0){
        vector<int> vec[100000];
        int visited[100000];
        memset(visited, -1, sizeof(visited));
        for(int i=0; i<n; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            vec[a].push_back(b);
            vec[b].push_back(a);
            visited[a] = 0;
            visited[b] = 0;
        }
        int visited2[100000];
        for(int i=0; i<100000; i++)
            visited2[i] = visited[i];
        while(scanf("%d%d", &start, &ttl) != EOF && !(start == 0 && ttl == 0)){
            for(int i=0; i<100000; i++)
                visited[i] = visited2[i];
            visited[start] = 1;
            queue<int> q, temp;
            q.push(start);
            int ttl2 = ttl;
            while(ttl > 0){
                while(!q.empty()){
                    int now = q.front();
                    q.pop();
                    for(auto i: vec[now]){
                        if(!visited[i]){
                            temp.push(i);
                            visited[i] = 1;
                        }
                    }
                }
                swap(q, temp);
                ttl--;
            }
            int count = 0;
            for(int i=0; i<100000; i++){
                if(!visited[i])
                    count++;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", test++, count, start, ttl2);
        }
    }
    return 0;
}


