#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    char s[25], t[25];
    scanf("%d", &test);
    while(test--){
        scanf("%s%s", s, t);
        bool pass = true;
        if(strlen(s) < strlen(t))
            pass = false;
        else{
            for(int i=0; i<strlen(t); i++){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                    if(!(t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u')){
                        pass = false;
                        break;
                    }
                }
                else if(s[i] != t[i]){
                    pass = false;
                    break;
                }
            }
        }
        if(pass)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

