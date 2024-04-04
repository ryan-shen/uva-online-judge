#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
double Calculator(char* str){
    int sum = 0;
    for(int i=0; i<strlen(str); i++){
        if(isalpha(str[i]))
            sum += tolower(str[i]) - 'a' + 1;
    }
    while(sum >= 10)
        sum = sum / 10 + sum % 10;
    return sum;
}
int main(int argc, const char * argv[]) {
    char a[26], b[26];
    while(cin.getline(a, 26)){
        cin.getline(b, 26);
        double sumA = Calculator(a);
        double sumB = Calculator(b);
        printf("%.2lf %%\n", min(sumA, sumB) / max(sumA, sumB) * 100);
    }
    return 0;
}

