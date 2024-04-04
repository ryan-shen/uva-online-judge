#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF && !(a == 0 && b == 0)){
        int sum = 0;
        for(int i=a; i<=b; i++)
            if((int)sqrt(i) * (int)sqrt(i) == i)
                sum++;
        printf("%d\n", sum);
    }
    return 0;
}

