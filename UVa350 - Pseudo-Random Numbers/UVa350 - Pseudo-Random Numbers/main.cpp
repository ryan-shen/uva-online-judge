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
    int a, b, c, d, test = 1;
    while(scanf("%d%d%d%d", &a, &b, &c, &d) != EOF && !(a == 0 && b == 0 && c == 0 && d == 0)){
        map<int, int> m;
        vector<int> vec;
        m[d]++;
        vec.push_back(d);
        while(1){
            int n = (a * d + b) % c;
            d = n;
            vec.push_back(n);
            if(m[n])
                break;
            else
                m[n]++;
        }
        int count = 0;
        for(auto i: vec){
            if(count)
                count++;
            if(i == d){
                if(count)
                    break;
                else
                    count = 1;
            }
        }
        printf("Case %d: %d\n", test++, count - 1);
    }
    return 0;
}


