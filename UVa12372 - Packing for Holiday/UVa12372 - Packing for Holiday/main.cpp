#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, a, b, c;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d%d%d", &a, &b, &c);
        if(a > 20 || b > 20 || c > 20)
            printf("Case %d: bad\n", k);
        else
            printf("Case %d: good\n", k);
    }
    return 0;
}
