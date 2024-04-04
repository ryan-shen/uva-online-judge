#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, test = 1;
    double u, a, t, v, s;
    while(scanf("%d", &n) != EOF && n != 0){
        printf("Case %d:", test++);
        switch(n){
            case 1:
                scanf("%lf%lf%lf", &u, &v, &t);
                a = (v - u) / t;
                s = (u + v) * t / 2;
                printf(" %.3lf %.3lf\n", s, a);
                break;
            case 2:
                scanf("%lf%lf%lf", &u, &v, &a);
                t = (v - u) / a;
                s = (u + v) * t / 2;
                printf(" %.3lf %.3lf\n", s, t);
                break;
            case 3:
                scanf("%lf%lf%lf", &u, &a, &s);
                v = sqrt(u * u + 2 * a * s);
                if(s < 0)
                    v = -v;
                t = (v - u) / a;
                printf(" %.3lf %.3lf\n", v, t);
                break;
            case 4:
                scanf("%lf%lf%lf", &v, &a, &s);
                u = sqrt(v * v - 2 * a * s);
                if(a > 0){
                    if(u > v)
                        u = -u;
                }
                else
                    if(u < v)
                        u = -u;
                t = (v - u) / a;
                printf(" %.3lf %.3lf\n", u, t);
        }
    }
    return 0;
}

