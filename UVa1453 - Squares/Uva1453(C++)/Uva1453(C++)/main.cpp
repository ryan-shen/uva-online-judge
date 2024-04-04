#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <functional>
#include <iostream>
#include <math.h>

using namespace std;

class Point{
    public:
    int x;
    int y;
    Point(){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

bool compare(Point p1, Point p2){
    if(p1.x < p2.x)
    return true;
    else if(p1.x == p2.x && p1.y < p2.y)
    return true;
    else
    return false;
}

int Vector(Point p1, Point p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

int main() {
    int test;
    scanf("%d", &test);
    while(test--) {
        int n;
        scanf("%d", &n);
        Point point[n*4];
        for(int i=0; i<n*4; i+=4) {
            int x, y, length;
            scanf("%d%d%d", &x, &y, &length);
            point[i] = Point(x, y);
            point[i+1] = Point(x + length, y);
            point[i+2] = Point(x, y + length);
            point[i+3] = Point(x + length, y + length);
        }
        sort(point, point+n*4, compare);
        vector<Point> convex;
        convex.push_back(point[0]);
        int convexIndex = 1;
        for(int i=1; i<n*4; i++) {
            convex.push_back(point[i]);
            if(convex.at(convexIndex).x == convex.at(convexIndex-1).x
               && convex.at(convexIndex).y >= convex.at(convexIndex-1).y) {
                convex.erase(convex.begin()+convexIndex);
                continue;
            }
            convexIndex++;
            int area = 0;
            while(area <= 0 && convex.size() >= 3) {
                Point vector1 = Point(convex.at(convexIndex-2).x - convex.at(convexIndex-3).x,
                                      convex.at(convexIndex-2).y - convex.at(convexIndex-3).y);
                Point vector2 = Point(convex.at(convexIndex-1).x - convex.at(convexIndex-2).x,
                                      convex.at(convexIndex-1).y - convex.at(convexIndex-2).y);
                area = Vector(vector1, vector2);
                if(area <= 0) {
                    convex.erase(convex.begin()+convexIndex-2);
                    convexIndex--;
                }
            }
        }
        for(int i=n*4-1; i>0; i--) {
            convex.push_back(point[i]);
            if(convex.at(convexIndex).x == convex.at(convexIndex-1).x
               && convex.at(convexIndex).y <= convex.at(convexIndex-1).y) {
                convex.erase(convex.begin()+convexIndex);
                continue;
            }
            convexIndex++;
            int area = 0;
            while(area <= 0 && convex.size() >= 3) {
                Point vector1 = Point(convex.at(convexIndex-2).x - convex.at(convexIndex-3).x,
                                      convex.at(convexIndex-2).y - convex.at(convexIndex-3).y);
                Point vector2 = Point(convex.at(convexIndex-1).x - convex.at(convexIndex-2).x,
                                      convex.at(convexIndex-1).y - convex.at(convexIndex-2).y);
                area = Vector(vector1, vector2);
                if(area <= 0) {
                    convex.erase(convex.begin()+convexIndex-2);
                    convexIndex--;
                }
            }
        }
        int maxValue = 0;
        for(auto it1 = convex.begin(); it1 != convex.end()-1; it1++) {
            for(auto it2 = it1+1; it2 != convex.end(); it2++) {
                double difX = pow(it2->x - it1->x, 2);
                double difY = pow(it2->y - it1->y, 2);
                maxValue = max(maxValue, (int)(difX + difY));
            }
        }
        printf("%d\n", maxValue);
    }
    return 0;
}



