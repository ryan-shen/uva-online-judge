#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char s[50];
    while(cin.getline(s, 50)){
        int sum = 0, exp = 0;
        if(s[0] == '_')
            continue;
        for(int i=strlen(s)-2; i>0; i--){
            if(s[i] == 'o'){
                sum += (1<<exp);
                exp++;
            }
            else if(s[i] == ' ')
                exp++;
        }
        printf("%c", (char)sum);
    }
    return 0;
}

