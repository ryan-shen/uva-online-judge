#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d", &n);
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        int high = 0;
        int low = 0;
        for(int i=0; i<n-1; i++){
            if(arr[i] < arr[i + 1])
                high++;
            else if(arr[i] > arr[i + 1])
                low++;
        }
        printf("Case %d: %d %d\n", k, high, low);
    }
    return 0;
}

