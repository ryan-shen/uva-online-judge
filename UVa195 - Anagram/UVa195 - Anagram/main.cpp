#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
bool cmp(char a, char b){
    if(tolower(a) == tolower(b))
       return a < b;
    else
       return tolower(a) < tolower(b);
}
int main(int argc, const char * argv[]) {
    int test;
    char str[100];
    scanf("%d", &test);
    while(test--){
        scanf("%s", str);
        sort(str, str+strlen(str), cmp);
        do{
            printf("%s\n", str);
        }while(next_permutation(str, str+strlen(str), cmp));
    }
    return 0;
}

