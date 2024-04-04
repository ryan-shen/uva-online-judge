#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int maxN = 5005;
int bit[5005];
int lowbit(int k){
    return k & -k;
}
void add(int x){
    while(x <= maxN){
        bit[x]++;
        x += lowbit(x);
    }
}
int sum(int x){
    int sum = 0;
    while(x > 0){
        sum += bit[x];
        x -= lowbit(x);
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    int test, n;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        memset(bit, 0, sizeof(bit));
        scanf("%d", &n);
        int arr[n], total = 0;
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
            if(i)
                total += sum(arr[i]);
            add(arr[i]);
        }
        printf("%d\n", total);
    }
    return 0;
}
