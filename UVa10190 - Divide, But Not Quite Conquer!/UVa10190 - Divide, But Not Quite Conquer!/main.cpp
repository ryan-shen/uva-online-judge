#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,m;
    while(scanf("%d%d", &n, &m) != EOF){
        int arr[100] = {n};
        int i = 1;
        while(n && m){
            if(n % m != 0 || n / m >= n)
                break;
            else{
                n /= m;
                arr[i++] = n;
            }
        }
        if(n == 1 && i > 1)
            for(int j=0; j<i; j++){
                if(j < i - 1)
                    printf("%d ", arr[j]);
                else
                    printf("%d", arr[j]);
            }
        else
            printf("Boring!");
        printf("\n");
    }
    return 0;
}

