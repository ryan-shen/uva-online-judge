#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[1000001], n;
    arr[0] = 1;
    for(int i=1; i<1000001; i++)
        arr[i] = (arr[(int)(i - sqrt(i))] + arr[(int)(log(i))] + arr[(int)(i * sin(i) * sin(i))]) % 1000000;
    while(scanf("%d", &n) != EOF && n != -1)
        printf("%d\n", arr[n]);
    return 0;
}

