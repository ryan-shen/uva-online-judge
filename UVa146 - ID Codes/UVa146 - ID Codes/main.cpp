#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    char arr[50];
    while(scanf("%s", arr) != EOF){
        if(arr[0] == '#')
            break;
        int n = strlen(arr);
        if(next_permutation(arr, arr+n))
            printf("%s\n", arr);
        else
            printf("No Successor\n");
    }
    return 0;
}

