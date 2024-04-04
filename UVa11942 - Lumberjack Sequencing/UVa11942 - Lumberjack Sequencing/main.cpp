#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, arr[10];
    scanf("%d", &test);
    printf("Lumberjacks:\n");
    while(test--){
        for(int i=0; i<10; i++)
            scanf("%d", &arr[i]);
        bool isOrdered = true;
        for(int i=1; i<9; i++){
            if((arr[i - 1] < arr[i]) ^ (arr[i] < arr[i + 1])){
                    isOrdered = false;
                    break;
            }
        }
        printf("%s\n", isOrdered ? "Ordered" : "Unordered");
    }
    return 0;
}

