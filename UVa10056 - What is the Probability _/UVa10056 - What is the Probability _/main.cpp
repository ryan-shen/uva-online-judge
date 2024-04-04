#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n, x;
    double p;
    scanf("%d", &test);
    for(int l=1; l<=test; l++){
        scanf("%d%lf%d", &n, &p, &x);
        double suc = p * pow(1 - p, x - 1);
        double total = suc;
        for(int i=1; ; i++){
            double fail = pow(1 - p, n);
            fail = pow(fail, i);
            if(total + fail * suc - total >= 0.000000001)
                total += fail * suc;
            else
                break;
        }
        printf("%.4lf\n", total);
    }
    return 0;
}
