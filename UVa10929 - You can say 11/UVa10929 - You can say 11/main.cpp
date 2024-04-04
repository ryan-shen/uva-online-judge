#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    char str[1001];
    while(scanf("%s", str) != EOF && !(strlen(str) == 1 && str[0] == '0')){
        int odd = 0;
        int even = 0;
        for(int i=0; i<strlen(str); i+=2)
            odd += (str[i] - 48);
        for(int i=1; i<strlen(str); i+=2)
            even += (str[i] - 48);
        if((odd - even) % 11 == 0)
            printf("%s is a multiple of 11.\n", str);
        else
            printf("%s is not a multiple of 11.\n", str);
    }
    return 0;
}

