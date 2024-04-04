#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    double b, s;
    int test = 1;
    while(scanf("%lf%lf", &b, &s) != EOF && !(b == 0 && s == 0)){
        printf("Case %d: ", test++);
        if(b - 1 == 0)
            printf(":-\\\n");
        else if((s - 1) / (b - 1) < s / b)
            printf(":-(\n");
        else
            printf(":-|\n");
    }
    return 0;
}


