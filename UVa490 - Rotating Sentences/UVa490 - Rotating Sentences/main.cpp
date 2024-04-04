#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test = 0, maxLen = 0;
    string s[105];
    while(getline(cin, s[test]))
        maxLen = max(maxLen, (int)s[test++].length());
    
    for(int i=0; i<maxLen; i++){
        for(int j=test-1; j>=0; j--){
            if(i >= s[j].length())
                printf(" ");
            else
                printf("%c", s[j][i]);
        }
        printf("\n");
    }
    return 0;
}


