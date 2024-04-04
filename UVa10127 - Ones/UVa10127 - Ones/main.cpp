#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
bool mod(int k){
    int seq[k];
    for(int i=0; i<k; i++)
        seq[i] = 1;
    for(int i=0; i<k-1; i++){
        seq[i+1] += seq[i] % n * 10;
    }
    return seq[k-1] % n == 0;
}
int main(int argc, const char * argv[]) {
    while(scanf("%d", &n) != EOF){
        int k = 1;
        while(!mod(k))
            k++;
        printf("%d\n", k);
    }
    return 0;
}

