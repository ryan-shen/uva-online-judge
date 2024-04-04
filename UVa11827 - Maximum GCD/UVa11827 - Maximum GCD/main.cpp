#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <sstream>
using namespace std;
int GCD(int a, int b){
    while(b % a){
        int temp = b % a;
        b = a;
        a = temp;
    }
    return a;
}
int main(int argc, const char * argv[]) {
    int test;
    string s;
    scanf("%d", &test);
    getchar();
    while(test--){
        int n, arr[101], index = 0;
        getline(cin, s);
        stringstream stream(s);
        while(stream >> n)
            arr[index++] = n;
        
        int gcd = 0;
        for(int i=0; i<index-1; i++)
            for(int j=i+1; j<index; j++)
                gcd = max(gcd, GCD(min(arr[i], arr[j]), max(arr[i], arr[j])));
        
        printf("%d\n", gcd);
    }
    return 0;
}

