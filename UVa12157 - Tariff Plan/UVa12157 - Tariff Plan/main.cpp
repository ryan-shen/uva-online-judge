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
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        int mile = 0, juice = 0;
        for(int i=0; i<n; i++){
            mile += (arr[i] / 30 + 1) * 10;
            juice += (arr[i] / 60 + 1) * 15;
        }
        printf("Case %d: ", k);
        if(mile < juice)
            printf("Mile %d\n", mile);
        else if(mile > juice)
            printf("Juice %d\n", juice);
        else
            printf("Mile Juice %d\n", mile);
    }
    return 0;
}
