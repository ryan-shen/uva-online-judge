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
        int count = 0;
        while(n > 0){
            if(n % 2){
                s += '1';
                count++;
            }
            else
                s += '0';
            n /= 2;
        }
        string r;
        for(auto it=s.rbegin(); it!=s.rend(); it++)
            r += *it;
        cout << "The parity of " << r << " is " << count << " (mod 2).\n";
    }
    return 0;
}

