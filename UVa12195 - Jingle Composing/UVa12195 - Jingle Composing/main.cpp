#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    char ch, s[205];
    map<char, double> m;
    m['W'] = 1;
    m['H'] = 1.0 / 2;
    m['Q'] = 1.0 / 4;
    m['E'] = 1.0 / 8;
    m['S'] = 1.0 / 16;
    m['T'] = 1.0 / 32;
    m['X'] = 1.0 / 64;
    while(scanf("%c", &ch) != EOF && ch != '*'){
        int sum = 0;
        double count = 0;
        cin.getline(s, 205);
        for(int i=0; i<strlen(s); i++){
            if(s[i] == '/'){
                if(count == 1)
                    sum++;
                count = 0;
            }
            else
                count += m[s[i]];
        }
        printf("%d\n", sum);
    }
    return 0;
}


