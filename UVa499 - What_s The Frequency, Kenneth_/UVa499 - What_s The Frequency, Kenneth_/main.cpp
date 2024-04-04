#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    while(getline(cin, s)){
        map<char, int> m;
        int maxValue = 0;
        for(int i=0; i<s.length(); i++){
            if(isalpha(s[i])){
                m[s[i]]++;
                maxValue = max(maxValue, m[s[i]]);
            }
        }
        for(auto i: m){
            if(i.second == maxValue)
                printf("%c", i.first);
        }
        printf(" %d\n", maxValue);
    }
    return 0;
}


