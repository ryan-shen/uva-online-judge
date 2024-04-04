#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    long long arr[10001];
    int k = 0;
    while(scanf("%lld", &arr[k++]) != EOF){
        sort(arr, arr+k);
        if(k % 2)
            printf("%lld\n", arr[k / 2]);
        else
            printf("%lld\n", (arr[k / 2] + arr[k / 2 - 1]) / 2);
    }
    return 0;
}

