#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <iostream>

using namespace std;

class Node{
    public:
    int curNode;
    int curOil;
    int cost;
    int weight;
    Node() {}
    Node(int curNode, int weight){
        this->curNode = curNode;
        this->weight = weight;
    }
    Node(int curNode, int curOil, int cost){
        this->curNode = curNode;
        this->curOil = curOil;
        this->cost = cost;
    }
    
};
inline bool compare(Node o1, Node o2) {
    return o1.cost > o2.cost;
}

int maxValue = 10000000;
int main() {
    int city, road;
    while(scanf("%d%d", &city, &road) != EOF) {
        int price[city];
        vector<Node> vec[city];
        for(int i=0; i<city; i++) {
            scanf("%d", &price[i]);
            
        }
        for(int i=0; i<road; i++) {
            int v1, v2, weight;
            scanf("%d%d%d", &v1, &v2, &weight);
            vec[v1].push_back(Node(v2, weight));
            vec[v2].push_back(Node(v1, weight));
        }
        int query;
        scanf("%d", &query);
        for(int k=0; k<query; k++) {
            priority_queue<Node, vector<Node>, function<bool(Node, Node)>> pq(compare);
            int capacity, v1, v2;
            scanf("%d%d%d", &capacity, &v1, &v2);
            int minCost[city][capacity];
            memset(minCost, 1, sizeof(minCost));
            bool pass = false;
            Node now;
            pq.push(Node(v1, 0, 0));
            minCost[v1][0] = 0;
            while(true) {
                if(pq.empty())
                break;
                now = pq.top();
                pq.pop();
                if(now.curNode == v2) {
                    pass = true;
                    break;
                }
                for(auto it=vec[now.curNode].begin(); it!=vec[now.curNode].end(); it++) {
                    if(it->weight <= capacity) {
                        if(now.curOil >= it->weight && minCost[it->curNode][now.curOil - it->weight] > now.cost
                           && price[it->curNode] < price[now.curNode]) {
                            pq.push(Node(it->curNode, now.curOil - it->weight, now.cost));
                            minCost[it->curNode][now.curOil - it->weight] = now.cost;
                            continue;
                        }
                        for(int j=0; j<=capacity-it->weight; j++) {
                            if(now.curOil >= j + it->weight && minCost[it->curNode][j] > now.cost) {
                                pq.push(Node(it->curNode, j, now.cost));
                                minCost[it->curNode][j] = now.cost;
                            }
                            else if(now.curOil < j + it->weight && minCost[it->curNode][j] >= now.cost + price[now.curNode] * (j + it->weight - now.curOil)){
                                pq.push(Node(it->curNode, j, now.cost + price[now.curNode] * (j + it->weight - now.curOil)));
                                minCost[it->curNode][j] = now.cost + price[now.curNode] * (j + it->weight - now.curOil);
                            }
                        }
                    }
                }
            }
            if(pass)
            printf("%d\n", now.cost);
            else
            printf("impossible\n");
        }
    }
}

