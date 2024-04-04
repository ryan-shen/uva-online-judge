#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF && !(a == 0 && b == 0)){
        int maxValue = 0, maxLen = 0;
        if(a > b) swap(a, b);
        for(int i=a; i<=b; i++){
            long long arr[10000], index = 0;
            arr[0] = i;
            do{
                index++;
                if(arr[index - 1] % 2){
                    arr[index] = 3 * arr[index - 1] + 1;
                }
                else{
                    arr[index] = arr[index - 1] / 2;
                }
            }while(arr[index] != 1);
            if(maxLen < index){
                maxLen = index;
                maxValue = i;
            }
        }
        printf("Between %d and %d, %d generates the longest sequence of %d values.\n", a, b, maxValue, maxLen);
    }
    return 0;
}


