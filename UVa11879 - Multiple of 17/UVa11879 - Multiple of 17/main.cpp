#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char s[105];
    while(scanf("%s", s) != EOF && s[0] != '0'){
        int sum = 0;
        for(int i=0; i<strlen(s); i++){
            sum *= 10;
            sum += s[i] - '0';
            sum %= 17;
        }
        printf("%d\n", sum ? 0 : 1);
    }
    return 0;
}

