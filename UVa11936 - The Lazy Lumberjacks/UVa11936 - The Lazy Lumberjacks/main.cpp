#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, arr[3];
    scanf("%d", &test);
    while(test--){
        scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
        sort(arr, arr+3);
        printf("%s\n", arr[0] + arr[1] > arr[2] ? "OK" : "Wrong!!");
    }
    return 0;
}

