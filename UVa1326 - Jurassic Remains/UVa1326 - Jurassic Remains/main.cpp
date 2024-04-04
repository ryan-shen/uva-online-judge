#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
using namespace std;
//計算位元 1 的個數
int countBit1(int n){
    int count = 0;
    while(n){
        n &= n - 1;
        count++;
    }
    return count;
}
int main(int argc, const char * argv[]) {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        //中途相遇法 (Meet in the Middle)
        if(n % 2){
            n = n / 2 + 1;
            m = n - 1;
        }
        else{
            n /= 2;
            m = n;
        }
        int front[n], back[m];
        for(int i=0; i<n; i++){
            front[i] = 0;
            char c[50];
            scanf("%s", c);
            for(int j=0; j<strlen(c); j++){
                front[i] += 1<<(c[j] - 65);
            }
        }
        for(int i=0; i<m; i++){
            back[i] = 0;
            char c[50];
            scanf("%s", c);
            for(int j=0; j<strlen(c); j++){
                back[i] += 1<<(c[j] - 65);
            }
        }
        map<int, int> maps;
        int maxCount = 0;
        int maxValue = 0;
        //計算前半部 xor 值
        for(int i=0; i<(1<<n); i++){
            int result = 0;
            for(int j=0; j<n; j++){
                if((i & (1<<j)) == (1<<j)){
                    result ^= front[j];
                }
            }
            auto it = maps.find(result);
            if(it != maps.end()){
                if(countBit1(i) > countBit1(it->second)){
                    maps.erase(it);
                    maps.insert(pair<int, int>(result, i));
                }
            }
            else
                maps.insert(pair<int, int>(result, i));
        }
        //計算後半部 xor 值來比對，若相等則是一個解
        for(int i=0; i<(1<<m); i++){
            int result = 0;
            for(int j=0; j<m; j++){
                if((i & (1<<j)) == (1<<j)){
                    result ^= back[j];
                }
            }
            auto it = maps.find(result);
            if(it != maps.end()){
                int value = (it->second) ^ (i<<n);
                int count = countBit1(value);
                if(count > maxCount){
                    maxCount = count;
                    maxValue = value;
                }
            }
        }
        printf("%d\n", maxCount);
        for(int i=0; i<n+m; i++){
            if((maxValue & (1<<i)) == (1<<i)){
                printf("%d", i+1);
                if((2<<i) < maxValue)
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}


