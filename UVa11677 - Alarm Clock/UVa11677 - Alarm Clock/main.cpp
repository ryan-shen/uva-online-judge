#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int h1, m1, h2, m2;
    while(scanf("%d%d%d%d", &h1, &m1, &h2, &m2) != EOF && !(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)){
        int time = (h2 + 24 - h1) % 24 * 60 + (m2 - m1);
        printf("%d\n", time > 0 ? time : time + 1440);
    }
    return 0;
}

