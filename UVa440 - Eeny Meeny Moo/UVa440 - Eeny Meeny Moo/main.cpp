#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int Josephus(int n, int k){
    if(n == 1)
        return 0;
    return (Josephus(n - 1, k) + k) % n;
}
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        int index = 1;
        while(Josephus(n - 1, index) != 0)
            index++;
        printf("%d\n", index);
    }
    return 0;
}


