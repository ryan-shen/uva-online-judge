#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int k, eps = 0.000001;
    double initHigh, workCat;
    while(scanf("%lf%lf", &initHigh, &workCat) != EOF && !(!initHigh && !workCat)){
        int l = 0, r = 2147483647, mid;
        int n = 0;
        while(!n){
            mid = (l + r) / 2;
            printf("log(i+1) = %lf\n", log10(mid+1) *log10(workCat) );
            printf("log(initHigh)= %lf\n", log10(initHigh)*log10(mid));
            if(fabs(log(mid + 1) * log(workCat) - log(mid) * log(initHigh)) < eps)
                n = mid;
            else if(log(mid + 1) * log(workCat) - log(mid) * log(initHigh) > 0)
                r = mid - 1;
            else
                l = mid + 1;
        }
        k = log(n) / log(workCat);
        int notWorkCat = 0;
        int totalHigh = 0;
        for(int i=0; i<k; i++){
            notWorkCat += pow(n, i);
            totalHigh += initHigh * pow(1 / (n + 1), i);
        }
        totalHigh += initHigh * pow(1 / (n + 1), k);
        printf("%d %d\n", notWorkCat, totalHigh);
    }
    return 0;
}


