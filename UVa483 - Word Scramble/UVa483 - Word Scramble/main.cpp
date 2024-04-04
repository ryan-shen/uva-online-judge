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
        int start = 0;
        for(int i=0; i<=s.length(); i++){
            if(s[i] == ' ' || i == s.length()){
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        cout << s << endl;
    }
    return 0;
}


