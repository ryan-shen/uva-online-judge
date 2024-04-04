#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b, c, d, limit;
    while(scanf("%d%d%d%d%d", &a, &b, &c, &d, &limit) != EOF && !(a == 0 && b == 0 && c == 0 && d == 0 && limit == 0)){
        int sum = 0;
        for(int i=0; i<=limit; i++){
            int x = a * i * i + b * i + c;
            if(x % d == 0)
                sum++;
        }
        printf("%d\n", sum);
    }
    return 0;
}

