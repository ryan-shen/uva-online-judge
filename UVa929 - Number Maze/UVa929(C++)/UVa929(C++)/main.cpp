#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <functional>

using namespace std;

class Point{
    public:
    int x;
    int y;
    int weight;
    int minWeight = 10000000;
};

bool compare(Point a, Point b)
{
    return (a.minWeight>b.minWeight);
}

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int row,col;
        scanf("%d%d", &row, &col);
        priority_queue<Point,vector<Point>,function<bool(Point,Point)>> pq(compare);
        Point point[row][col];
        Point now;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                
                scanf("%d", &point[i][j].weight);
                point[i][j].x = i;
                point[i][j].y = j;
            }
        }
        point[0][0].minWeight = point[0][0].weight;
        pq.push(point[0][0]);
        while(true) {
            if(!pq.empty()) {
                now = pq.top();
                pq.pop();
                if(now.x == row-1 && now.y == col-1)
                break;
            }
            else
            break;
            if(now.y+1 < col && point[now.x][now.y+1].minWeight > point[now.x][now.y+1].weight + now.minWeight) {
                point[now.x][now.y+1].minWeight = point[now.x][now.y+1].weight + now.minWeight;
                pq.push(point[now.x][now.y+1]);
            }
            if(now.x+1 < row && point[now.x+1][now.y].minWeight > point[now.x+1][now.y].weight + now.minWeight) {
                point[now.x+1][now.y].minWeight = point[now.x+1][now.y].weight + now.minWeight;
                pq.push(point[now.x+1][now.y]);
            }
            if(now.y-1 >= 0 && point[now.x][now.y-1].minWeight > point[now.x][now.y-1].weight + now.minWeight) {
                point[now.x][now.y-1].minWeight = point[now.x][now.y-1].weight + now.minWeight;
                pq.push(point[now.x][now.y-1]);
            }
            if(now.x-1 >= 0 && point[now.x-1][now.y].minWeight > point[now.x-1][now.y].weight + now.minWeight) {
                point[now.x-1][now.y].minWeight = point[now.x-1][now.y].weight + now.minWeight;
                pq.push(point[now.x-1][now.y]);
            }
        }
        printf("%d\n",point[row-1][col-1].minWeight);
    }
    
}





