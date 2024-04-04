#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    char ch;
    scanf("%d", &test);
    getchar();
    for(int k=1; k<=test; k++){
        printf("Case %d: ", k);
        while(scanf("%c", &ch) != EOF && ch != '\n'){
            int count;
            scanf("%d", &count);
            for(int i=0; i<count; i++)
                printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}

