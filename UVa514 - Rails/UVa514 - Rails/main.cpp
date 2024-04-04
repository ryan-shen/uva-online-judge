#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        int arr[n];
        while(scanf("%d", &arr[0]) != EOF && arr[0] != 0){
            queue<int> q;
            stack<int> s;
            s.push(0);
            for(int i=1; i<=n; i++){
                if(i < n)
                    scanf("%d", &arr[i]);
                q.push(i);
            }
            q.push(0);
            
            bool pass = true;
            int index = 0;
            while(index < n){
                if(q.front() == arr[index]){
                    q.pop();
                    index++;
                }
                else if(s.top() == arr[index]){
                    s.pop();
                    index++;
                }
                else if(q.front() > arr[index] || q.front() == 0){
                    pass = false;
                    break;
                }
                else{
                    s.push(q.front());
                    q.pop();
                }
            }
            printf("%s\n", pass ? "Yes" : "No");
        }
        printf("\n");
    }
    return 0;
}


