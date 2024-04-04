#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
char s[105][105];
int n;
void Ship(int i, int j){
    s[i][j] = '.';
    if(i > 0 && (s[i - 1][j] == 'x' || s[i - 1][j] == '@'))
        Ship(i - 1, j);
    if(j < n - 1 && (s[i][j + 1] == 'x' || s[i][j + 1] == '@'))
        Ship(i, j + 1);
    if(i < n - 1 && (s[i + 1][j] == 'x' || s[i + 1][j] == '@'))
        Ship(i + 1, j);
    if(j > 0 && (s[i][j - 1] == 'x' || s[i][j - 1] == '@'))
        Ship(i, j - 1);
}
int main(int argc, const char * argv[]) {
    int test;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%s", s[i]);
        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i][j] == 'x'){
                    sum++;
                    Ship(i, j);
                }
            }
        }
        printf("Case %d: %d\n", k, sum);
    }
    return 0;
}

