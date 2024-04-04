#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF){
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        bool pass = true;
        if(n > 1){
            bool dif[n];
            memset(dif, false, sizeof(dif));
            for(int i=0; i<n-1; i++){
                if(abs(arr[i] - arr[i+1]) < n)
                   dif[abs(arr[i] - arr[i+1])] = true;
            }
            for(int i=1; i<n; i++){
                if(!dif[i]){
                    pass = false;
                    break;
                }
            }
        }
        if(pass)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}

