#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n){
        double arr[n];
        double avg = 0;
        for(int i=0; i<n; i++){
            scanf("%lf", &arr[i]);
            avg += arr[i];
        }
        avg = ((double)(int)(avg*100/n+0.5))/100;
        double high = 0, low = 0;
        for(int i=0; i<n; i++){
            if(arr[i] < avg)
                low += avg - arr[i];
            else if(arr[i] > avg)
                high += arr[i] - avg;
        }
        printf("$%.2lf\n", min(low, high));
    }
    return 0;
}

