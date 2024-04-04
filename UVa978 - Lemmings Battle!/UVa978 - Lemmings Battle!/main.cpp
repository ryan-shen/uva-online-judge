#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, field, greenN, blueN, temp;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        if(k > 1) printf("\n");
        priority_queue<int> green;
        priority_queue<int> blue;
        scanf("%d%d%d", &field, &greenN, &blueN);
        int g[field], b[field];
        for(int i=0; i<greenN; i++){
            scanf("%d", &temp);
            green.push(temp);
        }
        for(int i=0; i<blueN; i++){
            scanf("%d", &temp);
            blue.push(temp);
        }
        while(1){
            if(green.empty() && blue.empty()){
                printf("green and blue died\n");
                break;
            }
            else if(green.empty()){
                printf("blue wins\n");
                while(!blue.empty()){
                    printf("%d\n", blue.top());
                    blue.pop();
                }
                break;
            }
            else if(blue.empty()){
                printf("green wins\n");
                while(!green.empty()){
                    printf("%d\n", green.top());
                    green.pop();
                }
                break;
            }
            else{
                for(int i=0; i<field; i++){
                    if(!green.empty()){
                        g[i] = green.top();
                        green.pop();
                    }
                    else
                        g[i] = 0;
                    if(!blue.empty()){
                        b[i] = blue.top();
                        blue.pop();
                    }
                    else
                        b[i] = 0;
                }
                for(int i=0; i<field; i++){
                    if(g[i] > b[i]){
                        g[i] -= b[i];
                        green.push(g[i]);
                    }
                    else if(g[i] < b[i]){
                        b[i] -= g[i];
                        blue.push(b[i]);
                    }
                }
            }
        }
    }
    return 0;
}
