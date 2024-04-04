#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, query, k, num;
    while(scanf("%d%d", &n, &query) != EOF){
        map<int, vector<int>> m;
        for(int i=0; i<n; i++){
            scanf("%d", &num);
            m[num].push_back(i);
        }
        for(int q=0; q<query; q++){
            scanf("%d%d", &k, &num);
            printf("%d\n", m[num].size() >= k ? m[num][k - 1] + 1 : 0);
        }
    }
    return 0;
}


