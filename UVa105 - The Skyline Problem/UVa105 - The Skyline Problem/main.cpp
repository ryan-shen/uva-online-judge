#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int maxHigh[10000];
    int left, right, high;
    int maxRight = 0;
    memset(maxHigh, 0, sizeof(maxHigh));
    while (scanf("%d%d%d", &left, &high, &right) != EOF) {
        //對每個建築物的 left ~ right - 1 的高度與最高高度比對
        for(int i=left; i<right; i++)
            maxHigh[i] = max(maxHigh[i], high);
        maxRight = max(maxRight, right);
    }
    int curHigh = -1;
    for(int i=1; i<=maxRight; i++){
        //高度有變化時印出
        if(maxHigh[i] != curHigh){
            curHigh = maxHigh[i];
            printf("%d %d", i, maxHigh[i]);
            if(i < maxRight)
                printf(" ");
        }
    }
    printf("\n");
    return 0;
}

