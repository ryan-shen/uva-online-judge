#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        int a, b, c, d, meetLeft, meetRight, wifeLeft, wifeRight;
        scanf("%d:%d %d:%d", &a, &b, &c, &d);
        wifeLeft = a * 100 + b;
        wifeRight = c * 100 + d;
        if(wifeRight < wifeLeft)
            wifeRight += 2400;
        scanf("%d:%d %d:%d", &a, &b, &c, &d);
        meetLeft = a * 100 + b;
        meetRight = c * 100 + d;
        if(meetRight < meetLeft)
            meetRight += 2400;
        int left = max(wifeLeft, meetLeft);
        int right = min(wifeRight, meetRight);
        printf("Case %d: %s\n", k, left > right ? "Hits Meeting" : "Mrs Meeting");
    }
    return 0;
}
