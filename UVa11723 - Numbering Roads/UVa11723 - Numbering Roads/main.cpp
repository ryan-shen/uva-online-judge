#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int r, n, test = 1;
    while(scanf("%d%d", &r, &n) != EOF && !(r == 0 && n == 0)){
        int answer;
        printf("Case %d: ", test++);
        answer = (r - 1) / n;
        if(answer <= 26)
            printf("%d\n", answer);
        else
            printf("impossible\n");
    }
    return 0;
}

