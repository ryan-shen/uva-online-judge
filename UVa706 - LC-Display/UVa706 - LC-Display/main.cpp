#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
string digit[10] = {"-|| ||-", "  |  | ", "- |-| -", "- |- |-", " ||- | ",
                    "-| - |-", "-| -||-", "- |  | ", "-||-||-", "-||- |-"};
int main(int argc, const char * argv[]) {
    int s;
    char n[10];
    while(scanf("%d%s", &s, n) != EOF && !(s == 0 && n[0] == '0')){
        int row = 2 * s + 3, col = (s + 2) * strlen(n);
        for(int i=0; i<row; i++){
            for(int j=0; j<strlen(n); j++){
                if(j) printf(" ");
                for(int k=0; k<s+2; k++){
                    if(i == 0 || i == s + 1 || i == row - 1){
                        if(k == 0 || k == s + 2 - 1)
                            printf(" ");
                        else if(i == 0)
                            printf("%c", digit[n[j] - '0'][0]);
                        else if(i == s + 1)
                            printf("%c", digit[n[j] - '0'][3]);
                        else if(i == row - 1)
                            printf("%c", digit[n[j] - '0'][6]);
                    }
                    else{
                        if(k != 0 && k != s + 2 - 1)
                            printf(" ");
                        else if(i < s + 1){
                            if(k < s)
                                printf("%c", digit[n[j] - '0'][1]);
                            else
                                printf("%c", digit[n[j] - '0'][2]);
                        }
                        else{
                            if(k < s)
                                printf("%c", digit[n[j] - '0'][4]);
                            else
                                printf("%c", digit[n[j] - '0'][5]);
                        }
                    }
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}


