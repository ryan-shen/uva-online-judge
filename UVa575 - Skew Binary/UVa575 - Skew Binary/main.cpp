#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    while(cin >> s && s != "0"){
        int sum = 0;
        for(int i=s.size()-1; i>=0; i--)
            sum += (s[i] - '0') * (pow(2, s.size() - i) - 1);
        printf("%d\n", sum);
    }
    return 0;
}


