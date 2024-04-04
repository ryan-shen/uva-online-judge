#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    long long n, p;
    while(scanf("%lld", &n) != EOF){
        int turn = 0;
        p = 1;
        while(p < n){
            if(turn ^= 1){
                p *= 9;
                if(p >= n)
                    printf("Stan wins.\n");
            }
            else{
                p *= 2;
                if(p >= n)
                    printf("Ollie wins.\n");
            }
        }
    }
    return 0;
}


