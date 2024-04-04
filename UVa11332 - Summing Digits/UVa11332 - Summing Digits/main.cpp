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
        while(n >= 10){
            int temp = n % 10;
            n /= 10;
            n += temp;
        }
        printf("%d\n", n);
    }
    return 0;
}

