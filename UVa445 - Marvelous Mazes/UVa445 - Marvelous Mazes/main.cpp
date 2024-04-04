#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char c;
    string s;
    while(getline(cin, s)){
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])){
                for(int j=i+1; j<s.length(); j++){
                    if(!isdigit(s[j])){
                        c = s[j];
                        break;
                    }
                }
                for(int j=0; j<s[i]-'0'; j++){
                    if(c == 'b')
                        printf(" ");
                    else
                        printf("%c", c);
                }
            }
            else if(s[i] == '!')
                printf("\n");
        }
        printf("\n");
    }
    return 0;
}


