#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, arr[15], path[6];
bool visited[100];
void DFS(int preIndex, int layer){
    for(int i=preIndex; i<n; i++){
        if(!visited[arr[i]]){
            visited[arr[i]] = true;
            path[layer] = arr[i];
            if(layer == 5){
                for(int j=0; j<6; j++){
                    if(j) printf(" ");
                    printf("%d", path[j]);
                }
                printf("\n");
            }
            else
                DFS(i + 1, layer + 1);
            visited[arr[i]] = false;
        }
    }
}
int main(int argc, const char * argv[]) {
    int printLine = 0;
    while(scanf("%d", &n) != EOF && n != 0){
        if(printLine++) printf("\n");
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+n);
        memset(visited, false, sizeof(visited));
        DFS(0, 0);
    }
    return 0;
}


