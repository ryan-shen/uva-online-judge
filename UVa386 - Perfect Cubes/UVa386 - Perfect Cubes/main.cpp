#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    for(int a=2; a<=200; a++){
        for(int b=2; b<a; b++){
            for(int c=b; c<a; c++){
                for(int d=c; d<a; d++){
                    if(a*a*a == b*b*b + c*c*c + d*d*d)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                }
            }
        }
    }
    return 0;
}


