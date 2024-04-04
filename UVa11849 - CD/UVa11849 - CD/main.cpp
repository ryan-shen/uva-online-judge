#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0)){
        int arr1[n], arr2[m];
        for(int i=0; i<n; i++)
            scanf("%d", &arr1[i]);
        for(int i=0; i<m; i++)
            scanf("%d", &arr2[i]);
        int index1 = 0, index2 = 0, sum = 0;
        while(index1 < n && index2 < m){
            if(arr1[index1] == arr2[index2]){
                sum++;
                index1++;
                index2++;
            }
            else if(arr1[index1] < arr2[index2])
                index1++;
            else
                index2++;
        }
        printf("%d\n", sum);
    }
    return 0;
}

