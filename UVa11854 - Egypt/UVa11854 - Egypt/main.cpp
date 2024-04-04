#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[3];
    while(scanf("%d%d%d", &arr[0], &arr[1], &arr[2]) != EOF && !(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)){
        sort(arr, arr+3);
        printf("%s\n", arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2] ? "right" : "wrong");
    }
    return 0;
}

