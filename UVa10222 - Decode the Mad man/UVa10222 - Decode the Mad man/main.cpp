#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char s[1000];
    char key[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    while(cin.getline(s, 1000)){
        for(int i=0; i<strlen(s); i++){
            for(int j=0; j<strlen(key); j++){
                if(key[j] == _tolower(s[i])){
                    printf("%c", key[j-2]);
                    break;
                }
                else if(j == strlen(key)-1){
                    printf("%c", s[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

