#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int person, budget, hotelN, bedN;
    while(scanf("%d%d%d%d", &person, &budget, &hotelN, &bedN) != EOF){
        int bed[hotelN][bedN];
        int hotelPrice[hotelN];
        int cost = 10000000;
        for(int i=0; i<hotelN; i++){
            scanf("%d", &hotelPrice[i]);
            for(int j=0; j<bedN; j++){
                scanf("%d", &bed[i][j]);
            }
        }
        for(int i=0; i<hotelN; i++){
            for(int j=0; j<bedN; j++){
                if(bed[i][j] >= person)
                    cost = min(cost, hotelPrice[i] * person);
            }
        }
        if(cost <= budget)
            printf("%d\n", cost);
        else
            printf("stay home\n");
    }
    return 0;
}

