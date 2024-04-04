#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n >= 0){
        vector<int> vec;
        while(n > 0){
            vec.push_back(n % 3);
            n /= 3;
        }
        for(auto it = vec.rbegin(); it != vec.rend(); it++)
            printf("%d", *it);
        if(!vec.empty())
            printf("\n");
        else
            printf("0\n");
    }
    return 0;
}

