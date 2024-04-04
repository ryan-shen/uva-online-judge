#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <functional>
using namespace std;
class Node{
public:
    char ch;
    int n;
};
bool compare(Node a, Node b){
    return (a.n < b.n) || (a.n == b.n && a.ch > b.ch);
}
int main(int argc, const char * argv[]) {
    map<char, int> map;
    priority_queue<Node, vector<Node>, function<bool(Node,Node)>> pq(compare);
    char s[1000];
    int test;
    scanf("%d", &test);
    cin.getline(s, 1000);
    while(test--){
        cin.getline(s, 1000);
        for(int i=0; i<strlen(s); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                map[s[i]]++;
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                map[s[i] - 32]++;
            }
        }
    }
    for(auto it: map){
        Node node;
        node.ch = it.first;
        node.n = it.second;
        pq.push(node);
    }
    while(!pq.empty()){
        Node node = pq.top();
        pq.pop();
        printf("%c %d\n", node.ch, node.n);
    }
    return 0;
}

