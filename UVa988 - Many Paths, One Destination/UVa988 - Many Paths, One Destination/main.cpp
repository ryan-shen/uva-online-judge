#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int printLine = 0, answer, n;
    while(scanf("%d", &n) != EOF){
        bool death[n];
        int count[n];
        memset(death, false, sizeof(death));
        memset(count, 0, sizeof(count));
        if(printLine++) printf("\n");
        count[0] = 1;
        for(int i=0; i<n; i++){
            int choice, temp;
            scanf("%d", &choice);
            if(!choice)
                death[i] = true;
            for(int j=0; j<choice; j++){
                scanf("%d", &temp);
                count[temp] += count[i];
            }
        }
        answer = 0;
        for(int i=0; i<n; i++){
            if(death[i])
                answer += count[i];
        }
        printf("%d\n", answer);
    }
    return 0;
}


