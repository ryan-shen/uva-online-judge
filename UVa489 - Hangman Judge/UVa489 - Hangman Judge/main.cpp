#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    char answer[1000], guess[1000];
    while(scanf("%d", &n) != EOF && n != -1){
        scanf("%s%s", answer, guess);
        set<char> st;
        map<char, int> mp;
        for(int i=0; i<strlen(answer); i++)
            st.insert(answer[i]);
        
        int count = 0;
        int state = 0;
        for(int i=0; i<strlen(guess); i++){
            auto it = st.find(guess[i]);
            if(!mp[guess[i]]){
                if(it == st.end())
                    count++;
                else
                    st.erase(it);
                mp[guess[i]]++;
            }
            
            if(st.empty()){
                state = 1;
                break;
            }
            else if(count >= 7){
                state = -1;
                break;
            }
        }
        if(state == 1)
            printf("Round %d\nYou win.\n", n);
        else if(state == -1)
            printf("Round %d\nYou lose.\n", n);
        else
            printf("Round %d\nYou chickened out.\n", n);
        
        
    }
    return 0;
}


