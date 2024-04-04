#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int C(int a, int b){
    if(b == 1 || a - b == 1)
        return a;
    return C(a - 1, b - 1) + C(a - 1, b);
}
int main(int argc, const char * argv[]) {
    int n, test = 0;
    while(scanf("%d", &n) != EOF){
        if(test++) printf("\n");
        printf("%d\n", C(2 * n, n) / (n + 1));
    }
    return 0;
}


