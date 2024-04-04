#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int mod(int x, int y, int z){
    if(!y)
        return 1;
    else if(y == 1)
        return x;
    else if(y % 2)
        return mod(x, y - 1, z) * (x % z) % z;
    else
        return mod((x % z) * (x % z) % z, y / 2, z);
}
int main(int argc, const char * argv[]) {
    int x, y, z;
    while(scanf("%d%d%d", &x, &y, &z) != EOF){
        printf("%d\n", mod(x, y, z));
    }
    return 0;
}


