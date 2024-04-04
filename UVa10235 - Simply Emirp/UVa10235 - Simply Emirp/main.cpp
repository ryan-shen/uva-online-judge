#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
bool isPrime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF){
        int flag = 0;
        if(isPrime(n))
            flag++;
        int m = 0;
        int temp = n;
        while(n){
            m *= 10;
            m += n % 10;
            n /= 10;
        }
        n = temp;
        if(isPrime(m) && n != m)
            flag += 2;
        if(flag == 1)
            printf("%d is prime.\n", n);
        else if(flag == 3)
            printf("%d is emirp.\n", n);
        else
            printf("%d is not prime.\n", n);
        
    }
    return 0;
}

