#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        bool arr[n + 1];
        memset(arr, false, sizeof(arr));
        int count = 1;
        int now = 1;
        int remain = 1;
        int cycle = 0;
        if(n == 1)
            printf("Discarded cards:");
        else
            printf("Discarded cards: 1");
        arr[1] = true;
        while(count < n - 1){
            now++;
            if(now > n)
                now = 1;
            if(arr[now])
                continue;
            cycle++;
            if(cycle == 2){
                printf(", %d", now);
                arr[now] = true;
                cycle = 0;
                count++;
            }
        }
        for(int i=1; i<=n; i++){
            if(!arr[i]){
                remain = i;
                break;
            }
        }
        printf("\nRemaining card: %d\n", remain);
    }
    return 0;
}

