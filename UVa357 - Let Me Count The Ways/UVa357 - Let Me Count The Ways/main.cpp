#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    int coin[] = {1, 5, 10, 25, 50};
    long long way[30001];
    memset(way, 0, sizeof(way));
    way[0] = 1;
    for(int i=0; i<5; i++){
        for(int j=coin[i]; j<=30000; j++){
            way[j] += way[j - coin[i]];
        }
    }
    while(scanf("%d", &n) != EOF){
        if(way[n] == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", way[n], n);
    }
    return 0;
}


