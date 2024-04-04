#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n;
    int arr[100001] = {0};
    for(int i=1; i<=100000; i++){
        int temp = i;
        int add = i;
        while(add){
            temp += add % 10;
            add /= 10;
        }
        if(!arr[temp])
            arr[temp] = i;
    }
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d", &n);
        printf("%d\n", arr[n]);
    }
    return 0;
}
