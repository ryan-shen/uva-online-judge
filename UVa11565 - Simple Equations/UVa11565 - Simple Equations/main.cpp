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
    while(test--){
        int x = 0, y = 0, z = 0;
        scanf("%d%d%d", &a, &b, &c);
        for(int i=-100; i<=100; i++){
            if(i == 0)
                continue;
            double n = (2 * b * 1.0) / (a * a - 2 * a * i + 2 * i * i - c);
            if(n == i && x && y){
                z = i;
                break;
            }
            else if(n == i && x)
                y = i;
            else if(n == i)
                x = i;
        }
        if(z)
            printf("%d %d %d\n", x, y, z);
        else
            printf("No solution.\n");
    }
    return 0;
}

