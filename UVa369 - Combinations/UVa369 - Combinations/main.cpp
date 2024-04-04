#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, m;
    long long c[101][101];
    for(int i=1; i<=100; i++){
        for(int j=1; j<=i; j++){
            if(!j || j == i)
                c[i][j] = 1;
            else if(j == 1 || j == i - 1)
                c[i][j] = i;
            else
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    while(scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0))
        printf("%d things taken %d at a time is %lld exactly.\n", n, m, c[n][m]);
    
    return 0;
}


