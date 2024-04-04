#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b, c, d;
    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF && !(a == 0 && b == 0 && c == 0 && d == 0)){
        int degree = 1080;
        degree += (40 + a - b) % 40 * 9;
        degree += (40 + c - b) % 40 * 9;
        degree += (40 + c - d) % 40 * 9;
        printf("%d\n", degree);
    }
    return 0;
}

