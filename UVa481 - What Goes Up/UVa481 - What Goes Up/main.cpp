#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int n, arr[100000], tempLis[100000], pos[100000], seqIndex = 0, lisIndex = 1;
int main(int argc, const char * argv[]) {
    while(scanf("%d", &n) != EOF)
        arr[seqIndex++] = n;
    
    tempLis[0] = arr[0];
    pos[0] = 0;
    for(int i=1; i<seqIndex; i++){
        for(int j=0; j<lisIndex; j++){
            if(arr[i] <= tempLis[j]){
                pos[i] = j;
                tempLis[j] = arr[i];
                break;
            }
            else if(j == lisIndex - 1 && arr[i] > tempLis[j]){
                lisIndex++;
                pos[i] = j + 1;
                tempLis[j + 1] = arr[i];
                break;
            }
        }
    }
    int count = lisIndex - 1;
    vector<int> vec;
    printf("%d\n-\n", lisIndex);
    for(int i=seqIndex-1; i>=0; i--){
        if(pos[i] == count){
            vec.push_back(arr[i]);
            count--;
        }
        if(count < 0)
            break;
    }
    for(auto it=vec.rbegin(); it!=vec.rend(); it++)
        printf("%d\n", *it);
    
    return 0;
}


