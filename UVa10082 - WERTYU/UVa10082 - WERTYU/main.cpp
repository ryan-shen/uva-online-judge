#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char key[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char s[1000];
    while(cin.getline(s, 1000)){
        for(int i=0; i<strlen(s); i++){
            for(int j=0; j<strlen(key); j++){
                if(key[j] == s[i]){
                    printf("%c", key[j-1]);
                    break;
                }
                else if(j == strlen(key) - 1)
                    printf("%c", s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

