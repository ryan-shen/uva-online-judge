#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d", &n);
        if(n < 10){
            printf("%d\n", n);
            continue;
        }
        int arr[100];
        int index = 0;
        for(int i=9; i>=2; i--){
            while(n % i == 0){
                arr[index++] = i;
                n /= i;
            }
        }
        if(index && n == 1){
            for(int i=index-1; i>=0; i--)
                printf("%d", arr[i]);
            printf("\n");
        }
        else
            printf("-1\n");
        
    }
    return 0;
}
