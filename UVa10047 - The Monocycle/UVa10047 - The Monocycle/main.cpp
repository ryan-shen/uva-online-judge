#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
using namespace std;
class Circle{
public:
    int x;
    int y;
    int direction = 0;
    int color = 0;
    int count;
    Circle(){};
    Circle(int x, int y, int d, int c, int count): x(x), y(y), direction(d), color(c), count(count){};
};
Circle circle, goal;
int minCount;
int map[28][28];
int row, col;
int visited[26][26][4][5];
queue<Circle> q;
int BFS(){
    while(!q.empty()){
        Circle c = q.front();
        q.pop();
        if(c.x == goal.x && c.y == goal.y && c.color == goal.color)
            return c.count;
        //前進
        if(c.direction == 0 && map[c.x-1][c.y] == 0 && visited[c.x-1][c.y][c.direction][(c.color+1)%5] == -1){
            q.push(Circle(c.x-1, c.y, c.direction, (c.color+1)%5, c.count+1));
            visited[c.x-1][c.y][c.direction][(c.color+1)%5] = 1;
        }
        else if(c.direction == 1 && map[c.x][c.y+1] == 0 && visited[c.x][c.y+1][c.direction][(c.color+1)%5] == -1){
            q.push(Circle(c.x, c.y+1, c.direction, (c.color+1)%5, c.count+1));
            visited[c.x][c.y+1][c.direction][(c.color+1)%5] = 1;
        }
        else if(c.direction == 2 && map[c.x+1][c.y] == 0 && visited[c.x+1][c.y][c.direction][(c.color+1)%5] == -1){
            q.push(Circle(c.x+1, c.y, c.direction, (c.color+1)%5, c.count+1));
            visited[c.x+1][c.y][c.direction][(c.color+1)%5] = 1;
        }
        else if(c.direction == 3 && map[c.x][c.y-1] == 0 && visited[c.x][c.y-1][c.direction][(c.color+1)%5] == -1){
            q.push(Circle(c.x, c.y-1, c.direction, (c.color+1)%5, c.count+1));
            visited[c.x][c.y-1][c.direction][(c.color+1)%5] = 1;
        }
        //右轉
        if(visited[c.x][c.y][(c.direction+5)%4][c.color] == -1){
            q.push(Circle(c.x, c.y, (c.direction+5)%4, c.color, c.count+1));
            visited[c.x][c.y][(c.direction+5)%4][c.color] = 1;
        }
        //左轉
        if(visited[c.x][c.y][(c.direction+3)%4][c.color] == -1){
            q.push(Circle(c.x, c.y, (c.direction+3)%4, c.color, c.count+1));
            visited[c.x][c.y][(c.direction+3)%4][c.color] = 1;
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    int test = 1;
    while (scanf("%d%d", &row, &col) != EOF && !(row == 0 && col == 0)) {
        if(test > 1)
            printf("\n");
        char input[row][col];
        for(int i=0; i<row; i++)
            scanf("%s", input[i]);
        memset(map, -1, sizeof(map));
        for(int i=0; i<row; i++){
            for (int j=0; j<col; j++) {
                map[i+1][j+1] = 0;
                if(input[i][j] == '#')
                    map[i+1][j+1] = -1;
                else if(input[i][j] == 'S')
                    circle = Circle(i+1, j+1, 0, 0, 0);
                else if(input[i][j] == 'T')
                    goal = Circle(i+1, j+1, 0, 0, 0);
            }
        }
        memset(visited, -1, sizeof(visited));
        //清空 queue 並開始做 BFS
        queue<Circle> empty;
        swap(q, empty);
        q.push(circle);
        minCount = BFS();
        printf("Case #%d\n", test++);
        if(minCount != -1)
            printf("minimum time = %d sec\n", minCount);
        else
            printf("destination not reachable\n");
        
    }
    return 0;
}


