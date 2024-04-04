#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
        printf("%d\n", n * m - 1);
    return 0;
}

