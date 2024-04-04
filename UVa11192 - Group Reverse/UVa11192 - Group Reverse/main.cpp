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
        string s;
        cin >> s;
        int count = s.length() / n;
        for(int i=0; i<s.length(); i+=count)
            reverse(s.begin() + i, s.begin() + i + count);
        cout << s << endl;
    }
    return 0;
}

