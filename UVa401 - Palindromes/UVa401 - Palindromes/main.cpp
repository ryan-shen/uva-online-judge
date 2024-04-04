#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    char s[100];
    char m[] = "01SE0Z00800000000A000300HIL0JM0O0002TUVWXY5";
    while(scanf("%s", s) != EOF){
        int output = 3;
        int len = strlen(s) - 1;
        for(int i=0; i<=len/2; i++){
            if(s[i] != s[len - i] && s[i] != m[s[len - i] - '0'])
                output &= 0;
            else if(s[i] != m[s[len - i] - '0'])
                output &= 1;
            else if(s[i] != s[len - i])
                output &= 2;
        }
        if(!output)
            printf("%s -- is not a palindrome.\n\n", s);
        else if(output == 1)
            printf("%s -- is a regular palindrome.\n\n", s);
        else if(output == 2)
            printf("%s -- is a mirrored string.\n\n", s);
        else
            printf("%s -- is a mirrored palindrome.\n\n", s);
    }
    return 0;
}


