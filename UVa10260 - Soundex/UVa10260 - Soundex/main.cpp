#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char s[25];
    int key[] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};
    while(scanf("%s", s) != EOF){
        for(int i=0; i<strlen(s); i++){
            if(i > 0)
                if(key[s[i] - 'A'] == key[s[i-1] - 'A'])
                    continue;
            if(key[s[i] - 'A'])
                printf("%d", key[s[i] - 'A']);
        }
        printf("\n");
    }
    return 0;
}

