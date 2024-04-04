#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int n1, n2;
    while(scanf("%d%d", &n1, &n2) != EOF && !(n1 == 0 && n2 == 0)){
        int arr[11] = {0};
        int count = 0;
        for(int i=0; ; i++){
            arr[i] = n1 % 10 + n2 % 10;
            n1 /= 10;
            n2 /= 10;
            if(n1 == 0 && n2 == 0)
                break;
        }
        for(int i=0; i<11; i++){
            if(arr[i] >= 10){
                count++;
                arr[i+1]++;
            }
        }
        if(count > 1)
            printf("%d carry operations.\n", count);
        else if(count == 1)
            printf("1 carry operation.\n");
        else
            printf("No carry operation.\n");
    }
    return 0;
}

