#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n;
    char ch;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf(" %c %c %d", &ch, &ch, &n);
        long long arr[n][n];
        bool pass = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%lld", &arr[i][j]);
                if(arr[i][j] < 0)
                    pass = false;
            }
        }

        for(int i=0; i<n; i++){
            if(!pass || i > n / 2)
                break;
            for(int j=0; j<n; j++){
                if(arr[i][j] != arr[n - i - 1][n - j - 1]){
                    pass = false;
                    break;
                }
            }
        }
        if(pass)
            printf("Test #%d: Symmetric.\n", k);
        else
            printf("Test #%d: Non-symmetric.\n", k);
    }
    return 0;
}

