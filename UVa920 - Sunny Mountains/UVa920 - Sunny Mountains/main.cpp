#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
class Point{
public:
    int x;
    int y;
    Point(){};
    Point(int a, int b): x(a), y(b){};
};
bool cmp(Point a, Point b){
    return a.x > b.x;
}
int main(int argc, const char * argv[]) {
    int test, n;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        scanf("%d", &n);
        Point point[n];
        for(int i=0; i<n; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            point[i] = Point(a, b);
        }
        sort(point, point+n, cmp);
        int y = point[0].y;
        int preX = point[0].x;
        int preY = point[0].y;
        double sum = 0;
        for(int i=1; i<n; i++){
            if(point[i].y > y){
                sum += sqrt(pow(point[i].y - y, 2) + pow((point[i].y - y) * (preX - point[i].x) * 1.0 / (point[i].y - preY), 2));
                y = point[i].y;
            }
            //point[i].y - y : point[i].y - preY = z : preX - point[i].x
            
            preX = point[i].x;
            preY = point[i].y;
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}
