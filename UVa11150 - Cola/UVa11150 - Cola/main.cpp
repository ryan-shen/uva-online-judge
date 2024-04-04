#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF){
        //每兩個可樂就跟朋友借一個瓶子
        printf("%d\n", n * 3 / 2);
    }
    return 0;
}

