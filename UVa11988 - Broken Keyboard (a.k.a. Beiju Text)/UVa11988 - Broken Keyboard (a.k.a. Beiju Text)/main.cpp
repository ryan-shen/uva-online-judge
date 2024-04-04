#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <list>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    while(getline(cin, s)){
        list<char> vec;
        list<char>::iterator it;
        bool front = false;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '['){
                front = true;
                it = vec.begin();
            }
            else if(s[i] == ']')
                front = false;
            else if(front)
                vec.insert(it, s[i]);
            else
                vec.push_back(s[i]);
        }
        for(auto i: vec)
            printf("%c", i);
        printf("\n");
    }
    return 0;
}


