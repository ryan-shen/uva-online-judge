#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
class Point{
public:
    int x;
    int y;
    int count;
    Point(int a, int b, int c): x(a), y(b), count(c){};
    bool operator==(Point a){
        return a.x == x && a.y == y;
    }
};
int main(int argc, const char * argv[]) {
    char a, c;
    int b, d;
    while(scanf("%c%d %c%d", &a, &b, &c, &d) != EOF){
        int x1 = a - 'a', y1 = b - 1, x2 = c - 'a', y2 = d - 1;
        queue<Point> q;
        q.push(Point(x1, y1, 0));
        Point goal = Point(x2, y2, 0);
        while(!(q.front() == goal)){
            Point now = q.front();
            q.pop();
            if(now.x < 0 || now.y < 0 || now.x > 7 || now.y > 7)
                continue;
            q.push(Point(now.x + 1, now.y + 2, now.count + 1));
            q.push(Point(now.x + 1, now.y - 2, now.count + 1));
            q.push(Point(now.x - 1, now.y + 2, now.count + 1));
            q.push(Point(now.x - 1, now.y - 2, now.count + 1));
            q.push(Point(now.x + 2, now.y + 1, now.count + 1));
            q.push(Point(now.x + 2, now.y - 1, now.count + 1));
            q.push(Point(now.x - 2, now.y + 1, now.count + 1));
            q.push(Point(now.x - 2, now.y - 1, now.count + 1));
        }
        printf("To get from %c%d to %c%d takes %d knight moves.\n", a, b, c, d, q.front().count);
        getchar();
    }
    return 0;
}


