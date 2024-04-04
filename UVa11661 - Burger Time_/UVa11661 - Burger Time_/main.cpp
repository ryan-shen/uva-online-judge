#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    char s[2000005];
    while(scanf("%d", &n) != EOF && n != 0){
        scanf("%s", s);
        int dist = 10000000;
        int rpos = 10000000;
        int dpos = 20000000;
        for(int i=0; i<strlen(s); i++){
            if(s[i] == 'Z'){
                dist = 0;
                break;
            }
            else if(s[i] == 'R'){
                rpos = i;
                dist = min(dist, abs(rpos - dpos));
            }
            else if(s[i] == 'D'){
                dpos = i;
                dist = min(dist, abs(rpos - dpos));
            }
        }
        printf("%d\n", dist);
    }
    return 0;
}

