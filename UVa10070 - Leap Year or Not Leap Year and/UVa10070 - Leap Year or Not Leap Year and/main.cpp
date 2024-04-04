#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
char year[100000];
int digit[100000];
int mod(int m){
    for(int i=0; i<strlen(year); i++)
        digit[i] = year[i] - '0';
    for(int i=0; i<strlen(year)-1; i++)
        digit[i+1] += digit[i] % m * 10;
    return digit[strlen(year)-1] % m;
}
int main(int argc, const char * argv[]) {
    bool printLine = false;
    while(scanf("%s", year) != EOF){
        if(printLine)
            printf("\n");
        int pass = 0;
        if(mod(4) == 0){
            if(mod(100) != 0 || mod(400) == 0){
                printf("This is leap year.\n");
                pass++;
            }
        }
        if(mod(15) == 0){
            printf("This is huluculu festival year.\n");
            pass += 2;
        }
        if(mod(55) == 0 && (pass & 1) == 1){
            printf("This is bulukulu festival year.\n");
            pass += 4;
        }
        if(!pass)
            printf("This is an ordinary year.\n");
        
        printLine = true;
    }
    return 0;
}

