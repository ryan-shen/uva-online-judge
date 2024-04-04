#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int mod(int x, int y, int m){
    if(!y)
        return 1;
    else if(y == 1)
        return x;
    else if(y % 2)
        return mod(x, y - 1, m) * x % m;
    else
        return mod(x * x % m, y / 2, m);
}
int main(int argc, const char * argv[]) {
    int index = 0;
    string s;
    map<char, int> m;
    for(char i='0'; i<='9'; i++)
        m[i] = index++;
    for(char i='A'; i<='Z'; i++)
        m[i] = index++;
    for(char i='a'; i<='z'; i++)
        m[i] = index++;
    
    while(getline(cin, s)){
        int minBase = 0;
        string str = "";
        for(int i=0; i<s.size(); i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                str += s[i];
                minBase = max(minBase, m[s[i]] + 1);
            }
        }
        s = str;
        if(minBase <= 2){
            printf("2\n");
            continue;
        }
        for(int i=minBase; i<=62; i++){
            int n = 0;
            int degree = 0;
            for(int j=s.size()-1; j>=0; j--)
                n += m[s[j]] * mod(i, degree++, i - 1);
            
            if(n % (i - 1) == 0){
                printf("%d\n", i);
                break;
            }
            else if(i == 62)
                printf("such number is impossible!\n");
        }
    }
    return 0;
}


