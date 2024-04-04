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
    while(test--){
        int days, n;
        scanf("%d%d", &days, &n);
        int day[days+1];
        int party[n+1];
        for(int i=1; i<=n; i++)
            scanf("%d", &party[i]);
        
        for(int i=1; i<=days; i++)
            day[i] = 0;
        
        for(int i=1; i<=n; i++)
            for(int j=party[i]; j<=days; j+=party[i])
                day[j]++;
        
        int count = 0;
        for(int i=1; i<=days; i++)
            if(day[i] > 0 && i % 7 != 6 && i % 7 != 0)
                count++;
        
        printf("%d\n", count);
    }
    return 0;
}

