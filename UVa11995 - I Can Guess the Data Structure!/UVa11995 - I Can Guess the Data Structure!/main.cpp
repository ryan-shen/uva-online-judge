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
    while(scanf("%d", &n) != EOF){
        int inst, num;
        bool qpass = true, ppass = true, spass = true;
        queue<int> q;
        priority_queue<int> p;
        stack<int> s;
        for(int i=0; i<n; i++){
            int qpop = -1, ppop = -1, spop = -1;
            scanf("%d%d", &inst, &num);
            if(inst == 1){
                q.push(num);
                p.push(num);
                s.push(num);
            }
            else{
                if(!q.empty()){
                    qpop = q.front();
                    q.pop();
                }
                if(!p.empty()){
                    ppop = p.top();
                    p.pop();
                }
                if(!s.empty()){
                    spop = s.top();
                    s.pop();
                }
                if(qpop != num)
                    qpass = false;
                if(ppop != num)
                    ppass = false;
                if(spop != num)
                    spass = false;
            }
        }
        if(qpass || ppass || spass){
            if((qpass && ppass) || (ppass && spass) || (qpass && spass))
                printf("not sure\n");
            else if(qpass)
                printf("queue\n");
            else if(ppass)
                printf("priority queue\n");
            else
                printf("stack\n");
        }
        else
            printf("impossible\n");
    }
    return 0;
}


