#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int C(int a, int b){
    if(b == 0 || b == a)
        return 1;
    else if(b == 1 || b == a - 1)
        return a;
    else
        return C(a - 1, b - 1) + C(a - 1, b);
}
int main(int argc, const char * argv[]) {
    char s[10];
    while(scanf("%s", s) != EOF){
        bool pass = true;
        int sum = 0;
        for(int i=1; i<strlen(s); i++){
            if(s[i - 1] >= s[i]){
                pass = false;
                break;
            }
        }
        if(!pass){
            printf("0\n");
            continue;
        }
        for(int i=1; i<strlen(s); i++)
            sum += C(26, i);
        char c = 'a';
        for(int i=0; i<strlen(s); i++){
            for(; c<s[i]; c++){
                sum += C('z' - c, strlen(s) - i - 1);
            }
            c++;
        }
        printf("%d\n", sum + 1);
    }
    return 0;
}


