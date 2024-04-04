#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF){
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+n);
        if(n % 2){
            int count = 0;
            for(int i=0; i<n; i++)
                if(arr[i] == arr[n / 2])
                    count++;
            printf("%d %d 1\n", arr[n / 2], count);
        }
        else{
            int count = 0;
            for(int i=0; i<n; i++)
                if(arr[i] == arr[n / 2] || arr[i] == arr[n / 2 - 1])
                    count++;
            printf("%d %d %d\n", arr[n / 2 - 1], count, arr[n / 2] - arr[n / 2 - 1] + 1);
        }
    }
    return 0;
}


