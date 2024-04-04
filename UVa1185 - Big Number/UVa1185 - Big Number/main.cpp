#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d", &n);
        double sum = 0;
        for(int i=1; i<=n; i++)
            sum += log10(i);
        printf("%d\n", (int)sum + 1);
    }
    return 0;
}
