#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    double x1, x2, x3, y1, y2, y3;
    while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF){
        double a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        double b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        double c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
        double s = (a + b + c) / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        double R = (a * b * c) / (4 * area);
        printf("%.2lf\n", 2 * R * M_PI);
    }
    return 0;
}


