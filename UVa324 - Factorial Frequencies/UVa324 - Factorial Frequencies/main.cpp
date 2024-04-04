#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int result[370][800];

int main(int argc, const char * argv[]) {
    int n, maxN = 366, maxDigit = 785;
    memset(result, 0, sizeof(result));
    result[1][0] = 1;
    for(int k=2; k<=maxN; k++){
        for(int j=0; j<=maxDigit; j++){
            result[k][j] += result[k - 1][j] * k;
            result[k][j + 1] += result[k][j] / 10;
            result[k][j] %= 10;
        }
    }
    while(scanf("%d", &n) != EOF && n != 0){
        bool lead = false;
        int count[10] = {0};
        printf("%d! --", n);
        for(int i=maxDigit; i>=0; i--){
            if(result[n][i])
                lead = true;
            if(lead){
                count[result[n][i]]++;
            }
        }
        for(int i=0; i<10; i++){
            if(i % 5 == 0)
                printf("\n   ");
            printf("(%d)%5d", i, count[i]);
            if((i + 1) % 5)
                printf("    ");
        }
        printf("\n");
    }
    return 0;
}


