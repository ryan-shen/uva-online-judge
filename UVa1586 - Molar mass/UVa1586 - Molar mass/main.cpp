#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    char s[85];
    map<char, double> m;
    m['C'] = 12.01;
    m['H'] = 1.008;
    m['O'] = 16;
    m['N'] = 14.01;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        double sum = 0;
        scanf("%s", s);
        for(int i=0; i<strlen(s); i++){
            if(isdigit(s[i + 1])){
                if(isdigit(s[i + 2]))
                    sum += m[s[i]] * ((s[i + 1] - '0') * 10 + (s[i + 2] - '0'));
                else
                    sum += m[s[i]] * (s[i + 1] - '0');
            }
            else
                sum += m[s[i]];
        }
        printf("%.3lf\n", sum);
    }
    return 0;
}
