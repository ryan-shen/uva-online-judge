#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n){
        int layer = 1;
        while(pow(layer, 2) < n)
            layer++;
        int row, col;
        bool pass = false;
        int now = pow(layer - 1, 2) + 1;
        if(layer % 2){
            for(int i=1; i<=layer; i++){
                row = i;
                col = layer;
                if(now++ == n){
                    pass = true;
                    break;
                }
            }
            if(!pass){
                for(int i=layer-1; i>0; i--){
                    row = layer;
                    col = i;
                    if(now++ == n){
                        pass = true;
                        break;
                    }
                }
            }
        }
        else{
            for(int i=1; i<=layer; i++){
                row = layer;
                col = i;
                if(now++ == n){
                    pass = true;
                    break;
                }
            }
            if(!pass){
                for(int i=layer-1; i>0; i--){
                    row = i;
                    col = layer;
                    if(now++ == n){
                        pass = true;
                        break;
                    }
                }
            }
        }
        printf("%d %d\n", col, row);
    }
    return 0;
}

