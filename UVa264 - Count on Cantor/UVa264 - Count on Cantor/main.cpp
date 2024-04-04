#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        int row = (-1 + sqrt(1 + 8 * n)) / 2;
        if((row + 1) * row / 2 == n){
            if(row % 2)
                printf("TERM %d IS 1/%d\n", n, row);
            else
                printf("TERM %d IS %d/1\n", n, row);
        }
        else{
            if(row % 2){
                int start = 1;
                int end = row + 1;
                for(int i=(row + 1) * row / 2 + 1; i!=n; i++){
                    start++;
                    end--;
                }
                printf("TERM %d IS %d/%d\n", n, start, end);
            }
            else{
                int start = row + 1;
                int end = 1;
                for(int i=(row + 1) * row / 2 + 1; i!=n; i++){
                    start--;
                    end++;
                }
                printf("TERM %d IS %d/%d\n", n, start, end);
            }
        }
    }
    return 0;
}


