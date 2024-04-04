#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int query;
    while(scanf("%d", &query) != EOF && query != 0){
        int dx, dy, x, y;
        scanf("%d%d", &dx, &dy);
        for(int i=0; i<query; i++){
            scanf("%d%d", &x, &y);
            x -= dx;
            y -= dy;
            if(x < 0 && y > 0)
                printf("NO\n");
            else if(x > 0 && y > 0)
                printf("NE\n");
            else if(x > 0 && y < 0)
                printf("SE\n");
            else if(x < 0 && y < 0)
                printf("SO\n");
            else
                printf("divisa\n");
        }
    }
    return 0;
}

