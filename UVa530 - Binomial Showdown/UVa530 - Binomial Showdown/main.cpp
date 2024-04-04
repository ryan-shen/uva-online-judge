#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    double n, k;
    while(scanf("%lf%lf", &n, &k) != EOF && !(n == 0 && k == 0)){
        if(n - k < k)
            k = n - k;
        double sum = 1;
        for(int i=0; i<k; i++)
            sum *= (n - i) / (k - i);
        printf("%lld\n", (long long)(sum + 0.001));
    }
    return 0;
}


