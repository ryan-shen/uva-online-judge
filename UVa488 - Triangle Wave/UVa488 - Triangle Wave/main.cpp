#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n, time;
    scanf("%d", &test);
    for(int k=0; k<test; k++){
        if(k) printf("\n");
        scanf("%d%d", &n, &time);
        for(int l=0; l<time; l++){
            if(l) printf("\n");
            for(int i=1; i<=n; i++){
                for(int j=1; j<=i; j++){
                    printf("%d", i);
                }
                printf("\n");
            }
            for(int i=n-1; i>0; i--){
                for(int j=i; j>0; j--){
                    printf("%d", i);
                }
                printf("\n");
            }
            
        }
    }
    return 0;
}
