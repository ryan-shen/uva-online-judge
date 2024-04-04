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
    string s;
    while(scanf("%d", &n) != EOF){
        vector<string> vec;
        int maxLen = 0;
        for(int i=0; i<n; i++){
            cin >> s;
            vec.push_back(s);
            maxLen = max(maxLen, (int)s.length());
        }
        
        sort(vec.begin(), vec.end());
        int column = 1 + (60 - maxLen) / (maxLen + 2);
        int maxRow = n / column + ((n % column != 0) ? 1 : 0);
        
        for(int i=0; i<60; i++)
            printf("-");
        printf("\n");
        for(int i=0; i<maxRow; i++){
            for(int j=0; j<column; j++){
                if(i + j * maxRow >= n)
                    break;
                if(j)
                    printf("  ");
                printf("%-*s", maxLen, vec[i + j * maxRow].c_str());
            }
            printf("\n");
        }
    }
    
    return 0;
}


