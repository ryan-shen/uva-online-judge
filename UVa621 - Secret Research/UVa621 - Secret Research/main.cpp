#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    string s;
    scanf("%d", &test);
    while(test--){
        cin >> s;
        if(s == "1" || s == "4" || s == "78")
            printf("+\n");
        else if(s[s.size() - 2] == '3' && s[s.size() - 1] == '5')
            printf("-\n");
        else if(s[0] == '9' && s[s.size() - 1] == '4')
            printf("*\n");
        else
            printf("?\n");
    }
    return 0;
}
