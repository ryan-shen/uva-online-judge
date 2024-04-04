#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    while(test--){
        int n;
        scanf("%d", &n);
        double arr[n], avg = 0;
        for(int i=0; i<n; i++){
            scanf("%lf", &arr[i]);
            avg += arr[i];
        }
        avg /= n;
        double percent = 0;
        for(int i=0; i<n; i++){
            if(arr[i] > avg)
                percent++;
        }
        printf("%.3lf%%\n", percent / n * 100);
    }
    return 0;
}

