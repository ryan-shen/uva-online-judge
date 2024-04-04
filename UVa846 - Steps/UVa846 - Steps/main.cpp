#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    long long x, y, step[132001];
    int test;
    int add = 0;
    step[0] = 0;
    for(int i=1; i<=132000; i++){
        if(i % 2)
            add++;
        step[i] = step[i - 1] + add;
    }
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%lld%lld", &x, &y);
        for(int i=0; i<=132000; i++){
            if(y - x <= step[i]){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
