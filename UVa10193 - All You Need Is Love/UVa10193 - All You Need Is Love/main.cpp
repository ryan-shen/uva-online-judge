#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
char s1[31], s2[31];
int GCD(int n1, int n2){
    while(n1 % n2){
        int temp = n1 % n2;
        n1 = n2;
        n2 = temp;
    }
    return n2;
}
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%s%s", s1, s2);
        int n1 = 0;
        int temp = 1;
        for(int i=strlen(s1)-1; i>=0; i--){
            n1 += (s1[i] - '0') * temp;
            temp *= 2;
        }
        int n2 = 0;
        temp = 1;
        for(int i=strlen(s2)-1; i>=0; i--){
            n2 += (s2[i] - '0') * temp;
            temp *= 2;
        }
        int answer = GCD(max(n1, n2), min(n1, n2));
        if(answer != 1)
            printf("Pair #%d: All you need is love!\n", k);
        else
            printf("Pair #%d: Love is not all you need!\n", k);
    }
    return 0;
}

