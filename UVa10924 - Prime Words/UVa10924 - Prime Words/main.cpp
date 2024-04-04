#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
bool isPrime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    char s[30];
    while(scanf("%s", s) != EOF){
        int sum = 0;
        for(int i=0; i<strlen(s); i++){
            if(islower(s[i]))
                sum += s[i] - 'a' + 1;
            else if(isupper(s[i]))
                sum += s[i] - 'A' + 27;
        }
        if(isPrime(sum))
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}

