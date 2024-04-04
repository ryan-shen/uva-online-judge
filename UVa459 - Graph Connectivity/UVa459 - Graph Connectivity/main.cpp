#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int parent[30];
int findParent(int x){
    while(parent[x] >= 0)
        x = parent[x];
    return x;
}
int main(int argc, const char * argv[]) {
    int test;
    string s;
    scanf("%d", &test);
    getchar();
    getchar();
    for(int k=1; k<=test; k++){
        if(k > 1) printf("\n");
        getline(cin, s);
        int size = s[0] - 'A' + 1;
        memset(parent, -1, sizeof(parent));
        while(getline(cin, s) && s != ""){
            int v1 = s[0] - 'A';
            int v2 = s[1] - 'A';
            int p1 = findParent(v1);
            int p2 = findParent(v2);
            if(p1 != p2){
                if(parent[p1] <= parent[p2]){
                    parent[p1] += parent[p2];
                    parent[p2] = p1;
                }
                else{
                    parent[p2] += parent[p1];
                    parent[p1] = p2;
                }
            }
        }
        int count = 0;
        for(int i=0; i<size; i++){
            if(parent[i] < 0)
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
