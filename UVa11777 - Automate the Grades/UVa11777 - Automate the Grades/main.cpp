#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        double arr[7];
        for(int i=0; i<7; i++)
            scanf("%lf", &arr[i]);
        
        sort(arr+4, arr+7, greater<double>());
        arr[4] = (arr[4] + arr[5]) / 2;
        
        double sum = 0;
        for(int i=0; i<5; i++)
            sum += arr[i];
        
        printf("Case %d: ", k);
        if(sum >= 90)
            printf("A\n");
        else if(sum >= 80)
            printf("B\n");
        else if(sum >= 70)
            printf("C\n");
        else if(sum >= 60)
            printf("D\n");
        else
            printf("F\n");
    }
    return 0;
}

