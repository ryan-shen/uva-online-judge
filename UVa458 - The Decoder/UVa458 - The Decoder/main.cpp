#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    while(getline(cin, s)){
        for(int i=0; i<s.length(); i++)
            printf("%c", s[i] - 7);
        printf("\n");
    }
    return 0;
}


