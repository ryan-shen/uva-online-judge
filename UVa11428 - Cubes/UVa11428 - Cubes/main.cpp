#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, table[101][101];
    for(int i=1; i<101; i++)
        for(int j=i+1; j<101; j++)
            table[i][j] = j * j * j - i * i * i;
    while(scanf("%d", &n) != EOF && n != 0){
        bool pass = false;
        for(int i=1; i<101; i++){
            for(int j=i+1; j<101; j++){
                if(table[i][j] == n){
                    printf("%d %d\n", j, i);
                    pass = true;
                    break;
                }
            }
            if(pass)
                break;
        }
        if(!pass)
            printf("No solution\n");
    }
    return 0;
}

