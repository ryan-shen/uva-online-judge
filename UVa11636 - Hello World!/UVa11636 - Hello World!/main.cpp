#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, test = 1;
    while(scanf("%d", &n) != EOF && n >= 0){
        int sum = 1;
        int copy = 0;
        while(sum < n){
            sum *= 2;
            copy++;
        }
        printf("Case %d: %d\n", test++, copy);
    }
    return 0;
}

