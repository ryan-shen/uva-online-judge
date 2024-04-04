#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    char vowel[] = "AEIOUaeiou";
    while(getline(cin, s)){
        int index = 0;
        for(int i=0; i<s.length(); i++){
            bool isVowel = false;
            if(isalpha(s[i])){
                for(int j=0; j<strlen(vowel); j++){
                    if(s[i] == vowel[j]){
                        isVowel = true;
                        break;
                    }
                }
                index = i;
                if(isVowel){
                    while(isalpha(s[index]))
                        printf("%c", s[index++]);
                }
                else{
                    char c = s[index++];
                    while(isalpha(s[index]))
                        printf("%c", s[index++]);
                    printf("%c", c);
                }
                printf("ay");
                i = index - 1;
            }
            else
                printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}


