#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    map<int, int> m;
    vector<int> vec;
    while(scanf("%d", &n) != EOF){
        m[n]++;
        auto it = find(vec.begin(), vec.end(), n);
        if(it == vec.end())
            vec.push_back(n);
    }
    for(auto i: vec)
        printf("%d %d\n", i, m[i]);
    
    return 0;
}


