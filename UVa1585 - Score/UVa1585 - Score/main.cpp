#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    char s[85];
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%s", s);
        int sum = 0;
        int add = 1;
        for(int i=0; i<strlen(s); i++){
            if(s[i] == 'O'){
                sum += add;
                add++;
            }
            else
                add = 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}
