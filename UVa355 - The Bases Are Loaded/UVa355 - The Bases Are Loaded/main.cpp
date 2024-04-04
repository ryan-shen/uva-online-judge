#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int from, to;
    char s[15];
    while(scanf("%d%d%s", &from, &to, s) != EOF){
        long long sum = 0;
        bool pass = true;
        for(int i=strlen(s)-1; i>=0; i--){
            if(isdigit(s[i])){
                if(s[i] - '0' >= from)
                    pass = false;
                sum += (s[i] - '0') * pow(from, strlen(s) - i - 1);
            }
            else{
                if(s[i] - 'A' + 10 >= from)
                    pass = false;
                sum += (s[i] - 'A' + 10) * pow(from, strlen(s) - i - 1);
            }
        }
        if(!pass){
            printf("%s is an illegal base %d number\n", s, from);
            continue;
        }
        
        int p = 0;
        while(pow(to, p + 1) <= sum) p++;
        string t;
        while(p >= 0){
            int n = sum / pow(to, p);
            if(n < 10)
                t += to_string(n);
            else
                t += 'A' + (n - 10);
            sum %= (long long)pow(to, p--);
        }
        
        printf("%s base %d = %s base %d\n", s, from, t.c_str(), to);
    }
    return 0;
}



