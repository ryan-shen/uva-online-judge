#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, a, b;
    scanf("%d", &test);
    while(test--){
        scanf("%d%d", &a, &b);
        if(a > b)
            printf(">\n");
        else if(a < b)
            printf("<\n");
        else
            printf("=\n");
    }
    return 0;
}

