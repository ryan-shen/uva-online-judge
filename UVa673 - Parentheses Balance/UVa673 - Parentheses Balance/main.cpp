#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    string s;
    scanf("%d", &test);
    getchar();
    while(test--){
        stack<char> st;
        st.push('0');
        getline(cin, s);
        bool pass = true;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == '[')
                st.push(s[i]);
            else if(s[i] == ')'){
                if(st.top() == '(')
                    st.pop();
                else{
                    pass = false;
                    break;
                }
            }
            else if(s[i] == ']'){
                if(st.top() == '[')
                    st.pop();
                else{
                    pass = false;
                    break;
                }
            }
        }
        if(st.top() != '0')
            pass = false;
        printf("%s\n", pass ? "Yes" : "No");
    }
    return 0;
}
