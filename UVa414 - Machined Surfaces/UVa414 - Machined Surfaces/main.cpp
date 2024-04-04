#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        getchar();
        string s[n];
        for(int i=0; i<n; i++)
            getline(cin, s[i]);
        
        int minBlank = 100, blank[n];
        for(int i=0; i<n; i++){
            blank[i] = 0;
            for(int j=0; j<s[i].length(); j++){
                if(s[i][j] == ' ')
                    blank[i]++;
            }
            minBlank = min(minBlank, blank[i]);
        }
        
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += blank[i] - minBlank;
        printf("%d\n", sum);
    }
    return 0;
}


