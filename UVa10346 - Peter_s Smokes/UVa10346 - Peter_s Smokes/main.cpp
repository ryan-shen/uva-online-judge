#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF){
        if(n % (k - 1))
            printf("%d\n", n + n / (k - 1));
        else
            printf("%d\n", n + n / (k - 1) - 1);
    }
    return 0;
}

