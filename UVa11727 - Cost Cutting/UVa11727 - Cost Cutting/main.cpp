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
    for(int k=1; k<=test; k++){
        int arr[3];
        scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
        sort(arr, arr+3);
        printf("Case %d: %d\n", k, arr[1]);
    }
    return 0;
}

