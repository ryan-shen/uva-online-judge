#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char x[255], y[255];
    while(scanf("%s%s", x, y) != EOF){
        int digitX[strlen(x)];
        int digitY[strlen(y)];
        int product[strlen(x) + strlen(y)];
        memset(product, 0, sizeof(product));
        for(int i=0; i<strlen(x); i++)
            digitX[i] = x[strlen(x) - i - 1] - '0';
        for(int i=0; i<strlen(y); i++)
            digitY[i] = y[strlen(y) - i - 1] - '0';
        for(int i=0; i<strlen(x); i++){
            for(int j=0; j<strlen(y); j++){
                product[i + j] += digitX[i] * digitY[j];
                product[i + j + 1] += product[i + j] / 10;
                product[i + j] %= 10;
            }
        }
        int totalLength = strlen(x) + strlen(y) - 1;
        while(totalLength > 0 && !product[totalLength])
            totalLength--;
        for(int i=totalLength; i>=0; i--)
            printf("%d", product[i]);
        printf("\n");
    }
    return 0;
}

