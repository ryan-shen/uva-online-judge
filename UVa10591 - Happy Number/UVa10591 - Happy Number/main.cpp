#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, test;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d", &n);
        set<int> s;
        int sum = n;
        while(s.find(sum) == s.end() && *(s.find(sum)) != 1){
            s.insert(sum);
            int temp = 0;
            while(sum > 0){
                temp += pow(sum % 10, 2);
                sum /= 10;
            }
            sum = temp;
        }
        if(sum == 1)
            printf("Case #%d: %d is a Happy number.\n", k, n);
        else
            printf("Case #%d: %d is an Unhappy number.\n", k, n);
    }
    return 0;
}

