#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int count = 1;
    int arr[1500];
    arr[0] = 1;
    printf("The 1500'th ugly number is ");
    while(count < 1500){
        int n = arr[count-1];
        int minValue = INT_MAX;
        for(int i=0; i<count; i++){
            if(arr[i] * 2 > n){
                minValue = min(minValue, arr[i] * 2);
                arr[count] = minValue;
                break;
            }
        }
        for(int i=0; i<count; i++){
            if(arr[i] * 3 > n){
                minValue = min(minValue, arr[i] * 3);
                arr[count] = minValue;
                break;
            }
        }
        for(int i=0; i<count; i++){
            if(arr[i] * 5 > n){
                minValue = min(minValue, arr[i] * 5);
                arr[count] = minValue;
                break;
            }
        }
        count++;
    }
    printf("%d.\n", arr[count-1]);
    return 0;
}
