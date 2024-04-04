#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, test = 1;
    while(scanf("%d", &n) != EOF && n != 0){
        printf("Game %d:\n", test++);
        int answer[n], guess[n], stateAnswer[n], stateGuess[n];
        for(int i=0; i<n; i++)
            scanf("%d", &answer[i]);
        while(1){
            int zero = 0;
            for(int i=0; i<n; i++){
                scanf("%d", &guess[i]);
                if(!guess[i])
                    zero++;
            }
            if(zero == n) break;
            
            int a = 0, b = 0;
            memset(stateAnswer, 0, sizeof(stateAnswer));
            memset(stateGuess, 0, sizeof(stateGuess));
            for(int i=0; i<n; i++){
                if(answer[i] == guess[i]){
                    a++;
                    stateAnswer[i] = 1;
                    stateGuess[i] = 1;
                }
            }
            for(int i=0; i<n; i++){
                if(!stateGuess[i]){
                    for(int j=0; j<n; j++){
                        if(!stateAnswer[j] && answer[j] == guess[i]){
                            b++;
                            stateAnswer[j] = 1;
                            stateGuess[i] = 1;
                            break;
                        }
                    }
                }
            }
            printf("    (%d,%d)\n", a, b);
        }
    }
    return 0;
}


