#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int countBit(int n){
    int bit = 0;
    while(n > 0){
        n &= n - 1;
        bit++;
    }
    return bit;
}
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);
        int temp = n;
        int m = 0;
        for(int i=0; temp>0; i++){
            m += temp % 10 * (1<<(4*i));
            temp /= 10;
        }
        printf("%d %d\n", countBit(n), countBit(m));
    }
    return 0;
}

