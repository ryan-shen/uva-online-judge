#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, table[1000001];
    for(int i=2; i<=1000000; i++)
        table[i] = 1;
    
    for(int i=2; i<=1000000; i++)
        if(table[i] == 1)
            for(int j=2; i*j<=1000000; j++)
                table[i * j] = table[i] + table[j];
    
    for(int i=3; i<=1000000; i++)
        table[i] += table[i - 1];
    
    while(scanf("%d", &n) != EOF)
        printf("%d\n", table[n]);
    
    return 0;
}


