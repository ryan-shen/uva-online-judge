#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n, m;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d", &n, &m);
        printf("%d\n", (n / 3) * (m / 3));
    }
    return 0;
}

