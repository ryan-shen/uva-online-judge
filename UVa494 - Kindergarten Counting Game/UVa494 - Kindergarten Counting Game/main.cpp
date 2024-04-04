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
        int count = 0;
        bool blank = true;
        for(int i=0; i<s.length(); i++){
            if(isalpha(s[i]) && blank){
                count++;
                blank = false;
            }
            else if(!isalpha(s[i]))
                blank = true;
        }
        printf("%d\n", count);
    }
    return 0;
}


