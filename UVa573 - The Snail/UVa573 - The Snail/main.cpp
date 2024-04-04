#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    double maxHigh, climb, slide, fatigue;
    while(scanf("%lf%lf%lf%lf", &maxHigh, &climb, &slide, &fatigue) != EOF && maxHigh != 0){
        double curHigh = 0;
        int day = 0;
        double minus = climb * fatigue / 100.0;
        while(1){
            day++;
            if(day > 1)
                climb -= minus;
            if(climb > 0){
                curHigh += climb;
                if(curHigh > maxHigh)
                    break;
            }
            curHigh -= slide;
            if(curHigh < 0)
                break;
        }
        if(curHigh > maxHigh)
            printf("success on day %d\n", day);
        else
            printf("failure on day %d\n", day);
    }
    return 0;
}


