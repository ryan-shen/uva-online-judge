#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    set<string> set;
    char s[5005];
    string word;
    while(scanf("%s", s) != EOF){
        word = "";
        for(int i=0; i<strlen(s); i++){
            if(isalpha(s[i])){
                word += s[i];
                if(i == strlen(s) - 1){
                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                    set.insert(word);
                    word = "";
                }
            }
            else if(word != ""){
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                set.insert(word);
                word = "";
            }
        }
    }
    for(auto it: set)
        cout << it << endl;
    return 0;
}

