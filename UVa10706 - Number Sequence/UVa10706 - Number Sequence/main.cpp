#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int maxIndex = 100001;
long long int digit[100001]; //每個數字佔的位元數
long long int sequence[100001]; //每個序列佔的位元數
long long int totalLength[100001]; //全部序列加起來佔的位元數
long long int pos;
void init(){
    for(int i=1; i<maxIndex; i++){
        int temp = i;
        digit[i] = 0;
        while(temp > 0){
            temp /= 10;
            digit[i]++;
        }
    }
    sequence[1] = 1;
    for(int i=2; i<maxIndex; i++){
        sequence[i] = sequence[i-1] + digit[i];
    }
    totalLength[1] = 1;
    for(int i=2; i<maxIndex; i++){
        totalLength[i] = totalLength[i-1] + sequence[i];
    }
}
int binarySearch(int left, int right){
    int mid = (left + right) / 2;
    if(left == right-1)
        return right;
    if(totalLength[mid] > pos)
        return binarySearch(left, mid);
    else if(totalLength[mid] < pos)
        return binarySearch(mid, right);
    else
        return mid;
}
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    init();
    while(test--){
        scanf("%lld", &pos);
        int bigIndex = binarySearch(1, maxIndex);
        long long int dif = totalLength[bigIndex] - pos + 1;
        int answer = -1;
        bool found = false;
        for(int i=bigIndex; i>=0; i--){
            int temp = i;
            while(temp > 0){
                answer = temp % 10;
                temp /= 10;
                dif--;
                if(dif <= 0){
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
        printf("%d\n", answer);
    }
    return 0;
}


