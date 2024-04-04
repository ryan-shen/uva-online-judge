#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, period;
    while(scanf("%d", &period) != EOF){
        scanf("%d", &n);
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        int maxValue = 0;
        int start = 0, end = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            int limit = arr[i] + period - 1;
            for(int j=i; j<n; j++){
                if(arr[j] <= limit)
                    sum++;
                else{
                    limit = arr[j - 1];
                    break;
                }
            }
            if(sum > maxValue){
                maxValue = sum;
                start = arr[i];
                end = limit;
            }
        }
        printf("%d %d %d\n", maxValue, start, end);
    }
    return 0;
}


