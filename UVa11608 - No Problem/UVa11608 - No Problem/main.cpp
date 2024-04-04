#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, test = 1;
    while(scanf("%d", &n) != EOF && n >= 0){
        int add[12];
        int need[12];
        for(int i=0; i<12; i++)
            scanf("%d", &add[i]);
        for(int i=0; i<12; i++)
            scanf("%d", &need[i]);
        printf("Case %d:\n", test++);
        for(int i=0; i<12; i++){
            if(n >= need[i]){
                printf("No problem! :D\n");
                n -= need[i];
            }
            else
                printf("No problem. :(\n");
            n += add[i];
        }
    }
    return 0;
}

