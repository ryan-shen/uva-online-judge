#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    string s, t;
    while(getline(cin, s)){
        if(!isdigit(s[0])){
            t = "";
            for(int i=0; i<s.size(); i++){
                int value = (int)s[i];
                t += to_string(value);
            }
            reverse(t.begin(), t.end());
            cout << t << endl;
        }
        else{
            t = "";
            reverse(s.begin(), s.end());
            int index = 0;
            while(index < s.size()){
                string ch = "";
                ch += s[index++];
                ch += s[index++];
                if(ch[0] == '1')
                    ch += s[index++];
                int value = stoi(ch);
                t += (char)value;
            }
            cout << t << endl;
        }
    }
    return 0;
}


