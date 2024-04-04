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
        int sum = 0;
        for(int i=1; i<=n; i++)
            sum += i * i;
        printf("%d\n", sum);
    }
    return 0;
}


