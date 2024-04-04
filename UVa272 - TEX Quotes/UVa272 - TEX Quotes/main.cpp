#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    char str[100];
    int quote = 1;
    while(cin.getline(str, 1000)){
        for(int i=0; i<strlen(str); i++){
            if(str[i] == '"'){
                if(quote)
                    printf("``");
                else
                    printf("\'\'");
                quote ^= 1;
            }
            else
                printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}

