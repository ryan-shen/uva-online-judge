#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int sum[110];
    bool lead;
    memset(sum, 0, sizeof(sum));
    char s[110];
    while(scanf("%s", s) != EOF && !(s[0] == '0' && s[1] == '\0')){
        int index = 0, arr[110];
        for(int i=strlen(s)-1; i>=0; i--)
            arr[index++] = s[i] - '0';
        
        for(int i=0; i<109; i++){
            if(i < index)
                sum[i] += arr[i];
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
    }
    lead = false;
    for(int i=109; i>=0; i--){
        if(sum[i])
            lead = true;
        if(lead)
            printf("%d", sum[i]);
    }
    printf("\n");
    return 0;
}


