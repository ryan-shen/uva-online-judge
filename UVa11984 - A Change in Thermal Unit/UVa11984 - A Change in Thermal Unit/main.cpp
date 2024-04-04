#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    double c, f, add;
    int test;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%lf%lf", &c, &add);
        f = 9.0 / 5 * c + 32 + add;
        c = (f - 32) * 5 / 9;
        printf("Case %d: %.2lf\n", k, c);
    }
    return 0;
}

