#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char s[35];
    int arr[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    while(scanf("%s", s) != EOF){
        for(int i=0; i<strlen(s); i++){
            if(isalpha(s[i]))
                printf("%d", arr[s[i] - 'A']);
            else
                printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}

