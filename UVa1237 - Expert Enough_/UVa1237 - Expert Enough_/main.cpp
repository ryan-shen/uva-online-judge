#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        if(k > 1) printf("\n");
        int n, q, query;
        scanf("%d", &n);
        int low[n], high[n];
        char name[n][25];
        for(int i=0; i<n; i++)
            scanf("%s%d%d", name[i], &low[i], &high[i]);
        
        scanf("%d", &query);
        int count, answer = 0;
        for(int i=0; i<query; i++){
            scanf("%d", &q);
            count = 0;
            for(int j=0; j<n; j++){
                if(low[j] <= q && high[j] >= q){
                    answer = j;
                    count++;
                }
            }
            if(count == 1)
                printf("%s\n", name[answer]);
            else
                printf("UNDETERMINED\n");
        }
    }
    return 0;
}
