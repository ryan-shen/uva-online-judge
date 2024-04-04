#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        int cost = 0, sum;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            int temp;
            scanf("%d", &temp);
            pq.push(temp);
        }
        for(int i=1; i<n; i++){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            sum = a + b;
            pq.push(sum);
            cost += sum;
        }
        printf("%d\n", cost);
    }
    return 0;
}

