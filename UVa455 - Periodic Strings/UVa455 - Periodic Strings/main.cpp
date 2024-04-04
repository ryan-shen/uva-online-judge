#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    string s, t;
    scanf("%d", &test);
    for(int l=0; l<test; l++){
        if(l) printf("\n");
        cin >> s;
        int period = 100;
        for(int i=0; i<s.length(); i++){
            t = "";
            for(int j=0; j<=i; j++){
                t += s[j];
            }
            bool matched = true;
            for(int j=0; j<s.length(); j+=t.length()){
                for(int k=0; k<t.length(); k++){
                    if(s[k + j] != t[k]){
                        matched = false;
                        break;
                    }
                }
                if(!matched)
                    break;
                else if(j == s.length() - t.length())
                    period = t.length();
            }
            if(period != 100)
                break;
        }
        printf("%d\n", period);
    }
    return 0;
}
