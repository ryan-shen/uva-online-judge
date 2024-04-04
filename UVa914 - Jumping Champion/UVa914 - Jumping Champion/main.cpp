#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int maxN = 1000001;
    bool primeTable[maxN];
    memset(primeTable, true, sizeof(primeTable));
    primeTable[0] = primeTable[1] = false;
    for(int i=2; i<maxN; i++){
        if(primeTable[i]){
            for(int j=i+i; j<maxN; j+=i)
                primeTable[j] = false;
        }
    }
    int test, a, b;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        map<int, int> m;
        scanf("%d%d", &a, &b);
        int p = 0;
        for(int i=a; i<=b; i++){
            if(primeTable[i]){
                if(p)
                    m[i - p]++;
                p = i;
            }
        }
        int maxNum = 0, maxValue = 0;
        bool pass = false;
        for(auto i: m){
            if(i.second > maxValue){
                maxValue = i.second;
                maxNum = i.first;
                pass = true;
            }
            else if(i.second == maxValue)
                pass = false;
        }
        if(pass)
            printf("The jumping champion is %d\n", maxNum);
        else
            printf("No jumping champion\n");
    }
    return 0;
}
