#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int m, s;
    while(scanf("%d:%d", &m, &s) != EOF && m != 0){
        double sd = s * 6;
        double md = m * 30 + s / 12.0 * 6;
        printf("%.3lf\n", abs(sd - md) > 180 ? 360 - abs(sd - md) : abs(sd - md));
    }
    return 0;
}


