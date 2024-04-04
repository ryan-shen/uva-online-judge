#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
class Node{
public:
    int from;
    int to;
};
bool cmp(Node a, Node b){
    return (a.from < b.from) || ((a.from == b.from) && (a.to < b.to));
}
int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d", &n) != EOF && n != 0) {
        Node a[500000], b[500000];
        for(int i=0; i<n; i++){
            scanf("%d%d", &a[i].from, &a[i].to);
            b[i].from = a[i].to;
            b[i].to = a[i].from;
        }
        sort(a, a+n, cmp);
        sort(b, b+n, cmp);
        bool pass = true;
        for(int i=0; i<n; i++){
            if(a[i].from != b[i].from || a[i].to != b[i].to){
                pass = false;
                break;
            }
        }
        if(pass)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

