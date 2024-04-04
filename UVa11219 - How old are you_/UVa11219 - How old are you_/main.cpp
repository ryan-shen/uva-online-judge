#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, age;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        int curY, curM, curD;
        int birY, birM, birD;
        scanf("%d/%d/%d", &curD, &curM, &curY);
        scanf("%d/%d/%d", &birD, &birM, &birY);
        
        age = curY - birY;
        if(curM - birM < 0)
            age--;
        else if(curM - birM == 0)
            if(curD - birD < 0)
                age--;
        
        if(curY < birY)
            printf("Case #%d: Invalid birth date\n", k);
        else if(curY == birY)
            if(curM < birM)
                printf("Case #%d: Invalid birth date\n", k);
            else if(curM > birM)
                printf("Case #%d: %d\n", k, age);
            else
                if(curD < birD)
                    printf("Case #%d: Invalid birth date\n", k);
                else
                    printf("Case #%d: %d\n", k, age);
        else if(age > 130)
            printf("Case #%d: Check birth date\n", k);
        else
            printf("Case #%d: %d\n", k, age);
    }
    return 0;
}

