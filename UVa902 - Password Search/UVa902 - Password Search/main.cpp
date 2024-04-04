#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    string s;
    while(scanf("%d", &n) != EOF){
        map<string, int> m;
        int maxValue = 0;
        string maxString;
        cin >> s;
        for(int i=0; i<=s.length()-n; i++){
            string temp = s.substr(i, n);
            if(++m[temp] > maxValue){
                maxValue = m[temp];
                maxString = temp;
            }
        }
        cout << maxString << '\n';
    }
    return 0;
}


