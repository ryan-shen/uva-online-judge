#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char s[1000001];
    int n, start, end, test = 1;
    while(scanf("%s", s) != EOF){
        scanf("%d", &n);
        printf("Case %d:\n", test++);
        for(int k=0; k<n; k++){
            int a, b;
            scanf("%d%d", &a, &b);
            start = min(a, b);
            end = max(a, b);
            bool pass = true;
            for(int i=start; i<end; i++){
                if(s[i] != s[i+1]){
                    pass = false;
                    break;
                }
            }
            if(pass)
                printf("Yes\n");
            else
                printf("No\n");
        }
        
    }
    return 0;
}

