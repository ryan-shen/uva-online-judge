#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    int test = 1;
    while(cin >> s && s != "*"){
        if(s == "Hajj")
            printf("Case %d: Hajj-e-Akbar\n", test++);
        else
            printf("Case %d: Hajj-e-Asghar\n", test++);
    }
    return 0;
}


