#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
class Job{
public:
    int n;
    bool mark;
    Job(){};
    Job(int a, bool b): n(a), mark(b){};
};
int main(int argc, const char * argv[]) {
    int test, n, pos;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d%d", &n, &pos);
        queue<Job> q;
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            int temp;
            scanf("%d", &temp);
            if(i == pos)
                q.push(Job(temp, true));
            else
                q.push(Job(temp, false));
            pq.push(temp);
        }
        int count = 0;
        int maxValue = pq.top();
        pq.pop();
        while(1){
            if(q.front().n == maxValue){
                count++;
                if(q.front().mark)
                    break;
                q.pop();
                maxValue = pq.top();
                pq.pop();
            }
            else{
                Job temp = q.front();
                q.pop();
                q.push(temp);
            }
            
        }
        printf("%d\n", count);
    }
    return 0;
}
