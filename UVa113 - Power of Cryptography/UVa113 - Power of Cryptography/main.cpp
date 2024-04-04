#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    double n, p;
    while (scanf("%lf%lf", &p, &n) != EOF) {
        printf("%.0lf\n", pow(n, 1 / p));
    }
    return 0;
}

