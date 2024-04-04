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
    while(test--){
        scanf("%d", &n);
        printf("%d\n", abs(((n * 567 / 9 + 7492) * 235 / 47 - 498) / 10 % 10));
    }
    return 0;
}

