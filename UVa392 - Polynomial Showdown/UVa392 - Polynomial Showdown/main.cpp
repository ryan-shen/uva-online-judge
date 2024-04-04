#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[9];
    while(scanf("%d", &arr[8]) != EOF){
        for(int i=7; i>=0; i--)
            scanf("%d", &arr[i]);
        
        bool lead = true;
        for(int i=8; i>=0; i--){
            if(arr[i]){
                if(!lead)
                    printf(" %s ", arr[i] > 0 ? "+" : "-");
                else if(arr[i] < 0)
                    printf("-");
                
                if(i > 1){
                    if(abs(arr[i]) != 1)
                        printf("%d", abs(arr[i]));
                    printf("x^%d", i);
                }
                else if(i == 1){
                    if(abs(arr[i]) != 1)
                        printf("%d", abs(arr[i]));
                    printf("x");
                }
                else
                    printf("%d", abs(arr[i]));
                lead = false;
            }
        }
        printf("%s", lead ? "0\n" : "\n");
    }
    return 0;
}


