#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    double a, b, c;
    while(scanf("%lf%lf%lf", &a, &b, &c) != EOF){
        double s = (a + b + c) / 2;
        double triangle = pow(s * (s - a) * (s - b) * (s - c), 0.5);
        double r = triangle / s;
        double smallCircle = r * r * M_PI;
        double R = a * b * c / (4 * triangle);
        double bigCircle = R * R * M_PI;
        printf("%.4lf %.4lf %.4lf\n", bigCircle - triangle, triangle - smallCircle, smallCircle);
    }
    return 0;
}

