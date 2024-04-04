#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int prime[3500];
void primeTable(){
    int n = 2;
    for(int index=0; index<3500;){
        bool pass = true;
        for(int i=2; i<=sqrt(n); i++){
            if(n % i == 0){
                pass = false;
                break;
            }
        }
        if(pass)
            prime[index++] = n;
        n++;
    }
}
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    primeTable();
    while (test--) {
        int start, end;
        scanf("%d%d", &start, &end);
        int maxValue = 0;
        int maxCount = 0;
        for(int i=start; i<=end; i++){
            int temp = i;
            int count = 1;
            int arr[3500] = {0};
            int index = 0;
            for(int j=0; temp!=1 && j<3500; j++){
                if(temp % prime[j] == 0){
                    while(temp % prime[j] == 0){
                        temp /= prime[j];
                        arr[index]++;
                    }
                    index++;
                }
            }
            for(int i=0; i<index; i++){
                count *= (arr[i] + 1);
            }
            if(maxCount < count){
                maxValue = i;
                maxCount = count;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", start, end, maxValue, maxCount);
    }
    return 0;
}

