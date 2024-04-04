#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    char s[10005];
    scanf("%d", &test);
    getchar();
    while(test--){
        cin.getline(s, 10005);
        int n = sqrt(strlen(s));
        if(n * n != strlen(s))
            printf("INVALID\n");
        else{
            char arr[n][n];
            int index = 0;
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    arr[i][j] = s[index++];
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    printf("%c", arr[j][i]);
            printf("\n");
        }
    }
    return 0;
}

