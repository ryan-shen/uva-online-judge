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
    char s[300];
    scanf("%d", &test);
    getchar();
    while(test--){
        cin.getline(s, 300);
        map<char, int> key;
        int frequency = 0;
        for(int i=0; i<strlen(s); i++){
            s[i] = tolower(s[i]);
            if(isalpha(s[i])){
                key[s[i]]++;
                frequency = max(frequency, key[s[i]]);
            }
        }
        for(auto i: key)
            if(i.second == frequency)
                printf("%c", i.first);
        printf("\n");
        
    }
    return 0;
}

