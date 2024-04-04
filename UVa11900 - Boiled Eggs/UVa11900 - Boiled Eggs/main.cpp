#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n, maxN, maxW;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d%d%d", &n, &maxN, &maxW);
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        int answer = maxN;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > maxW){
                answer = min(answer, i);
                break;
            }
            else if(i == n - 1)
                answer = min(answer, n);
        }
        printf("Case %d: %d\n", k, answer);
    }
    return 0;
}

