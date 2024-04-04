#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int answer[50];
    int answerIndex = 0;
    for(int i=2; i<=40000; i++){
        int n = i * i;
        int digit = 0;
        while(n > 0){
            digit++;
            n /= 10;
        }
        n = i * i;
        for(int j=1; j<digit; j++){
            int left = n / (int)pow(10, j);
            int right = n % (int)pow(10, j);
            if(left + right == i && right)
                answer[answerIndex++] = i;
        }
    }
    int test, a, b;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        if(k > 1) printf("\n");
        scanf("%d%d", &a, &b);
        printf("case #%d\n", k);
        bool pass = false;
        for(int i=0; i<answerIndex; i++){
            if(answer[i] >= a){
                if(answer[i] <= b){
                    pass = true;
                    printf("%d\n", answer[i]);
                }
                else
                    break;
            }
        }
        if(!pass)
            printf("no kaprekar numbers\n");
    }
    return 0;
}
