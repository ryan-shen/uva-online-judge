#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, i, v, x, l, c;
    while(scanf("%d", &n) != EOF && n != 0){
        i = v = x = l = c = 0;
        for(int j=1; j<=n; j++){
            int a = j / 10, b = j % 10;
            switch (a) {
                case 1: x++;         break;
                case 2: x += 2;      break;
                case 3: x += 3;      break;
                case 4: x++; l++;    break;
                case 5: l++;         break;
                case 6: x++; l++;    break;
                case 7: x += 2; l++; break;
                case 8: x += 3; l++; break;
                case 9: x++; c++;    break;
                case 10: c++;        break;
            }
            switch (b) {
                case 1: i++;         break;
                case 2: i += 2;      break;
                case 3: i += 3;      break;
                case 4: i++; v++;    break;
                case 5: v++;         break;
                case 6: i++; v++;    break;
                case 7: i += 2; v++; break;
                case 8: i += 3; v++; break;
                case 9: i++; x++;    break;
            }
        }
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i, v, x, l, c);
    }
    return 0;
}


