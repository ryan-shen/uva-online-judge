#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, table, value, line;
    unsigned char ch;
    scanf("%d", &test);
    while(test--){
        int map[300] = {0};
        scanf("%d", &table);
        for(int i=0; i<table; i++){
            scanf(" %c %d", &ch, &value);
            map[ch] = value;
        }
        
        double sum = 0;
        scanf("%d", &line);
        getchar();
        for(int i=0; i<line; i++)
            while(scanf("%c", &ch) != EOF && ch != '\n')
                sum += map[ch];
        
        printf("%.2lf$\n", sum / 100);
    }
    return 0;
}

