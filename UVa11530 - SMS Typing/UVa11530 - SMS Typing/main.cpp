#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    char s[105];
    scanf("%d", &test);
    int arr[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
    getchar();
    for(int k=1; k<=test; k++){
        cin.getline(s, 105);
        int sum = 0;
        for(int i=0; i<strlen(s); i++){
            if(s[i] == ' ')
                sum++;
            else
                sum += arr[s[i] - 'a'];
        }
        printf("Case #%d: %d\n", k, sum);
    }
    return 0;
}

