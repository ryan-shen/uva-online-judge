#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        if(n <= 100)
            printf("f91(%d) = 91\n", n);
        else
            printf("f91(%d) = %d\n", n, n - 10);
    }
    return 0;
}

