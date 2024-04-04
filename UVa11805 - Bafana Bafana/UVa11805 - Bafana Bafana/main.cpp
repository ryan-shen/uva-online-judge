#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n, k, p;
    scanf("%d", &test);
    for(int i=1; i<=test; i++){
        scanf("%d%d%d", &n, &k, &p);
        while(p--){
            if(++k > n)
                k = 1;
        }
        printf("Case %d: %d\n", i, k);
    }
    return 0;
}

