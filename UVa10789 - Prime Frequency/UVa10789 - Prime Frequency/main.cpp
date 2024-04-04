#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
bool isPrime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        char s[2005];
        map<char, int> map;
        scanf("%s", s);
        for(int i=0; i<strlen(s); i++){
            map[s[i]]++;
        }
        
        bool isEmpty = true;
        printf("Case %d: ", k);
        for(auto it: map){
            if(it.second > 1 && isPrime(it.second)){
                printf("%c", it.first);
                isEmpty = false;
            }
        }
        if(isEmpty)
            printf("empty\n");
        else
            printf("\n");
    }
    return 0;
}

