#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int from, to;
    char s[8];
    while(scanf("%s%d%d", s, &from, &to) != EOF){
        int sum = 0;
        for(int i=strlen(s)-1; i>=0; i--){
            if(isdigit(s[i]))
                sum += (s[i] - '0') * pow(from, strlen(s) - i - 1);
            else
                sum += (s[i] - 'A' + 10) * pow(from, strlen(s) - i - 1);
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
            sum %= (int)pow(to, p--);
        }

        if(t.size() > 7)
            printf("  ERROR\n");
        else
            printf("%7s\n", t.c_str());
    }
    return 0;
}


