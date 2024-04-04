#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, test = 1;
    while(scanf("%d", &n) != EOF && n != 0){
        int arr[n], avg = 0;
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
            avg += arr[i];
        }
        avg /= n;
        
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += (arr[i] > avg ? arr[i] - avg : 0);
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", test++, sum);
    }
    return 0;
}


