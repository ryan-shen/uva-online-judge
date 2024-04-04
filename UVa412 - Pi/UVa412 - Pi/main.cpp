#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int GCD(int a, int b){
    while(a){
        int temp = b % a;
        b = a;
        a = temp;
    }
    return b;
}
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        int count = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(GCD(min(arr[i], arr[j]), max(arr[i], arr[j])) == 1)
                    count++;
            }
        }
        if(!count)
            printf("No estimate for this data set.\n");
        else
            printf("%.6lf\n", sqrt(6.0 * (n * (n - 1) / 2) / count));
    }
    return 0;
}


