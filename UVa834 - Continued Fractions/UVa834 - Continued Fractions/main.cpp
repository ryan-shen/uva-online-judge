#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF){
        int index = 0, arr[1000];
        while(b){
            arr[index++] = a / b;
            a %= b;
            swap(a, b);
        }
        for(int i=0; i<index; i++){
            if(!i && i == index - 1)
                printf("[%d]\n", arr[i]);
            else if(!i)
                printf("[%d;", arr[i]);
            else if(i == index - 1)
                printf("%d]\n", arr[i]);
            else
                printf("%d,", arr[i]);
        }
    }
    return 0;
}


