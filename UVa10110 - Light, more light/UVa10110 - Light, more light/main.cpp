#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    long long n;
    while(scanf("%lld", &n) != EOF && n != 0){
        if((long long)sqrt(n) * (long long)sqrt(n) == n)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

