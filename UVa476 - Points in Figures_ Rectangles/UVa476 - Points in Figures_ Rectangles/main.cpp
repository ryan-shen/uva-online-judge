#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
class Rectangle{
public:
    double x1;
    double x2;
    double y1;
    double y2;
    Rectangle(){};
    Rectangle(double a, double b, double c, double d): x1(a), y1(b), x2(c), y2(d){};
};
int main(int argc, const char * argv[]) {
    int recIndex = 0, pointIndex = 1;
    double x1, x2, y1, y2, p1, p2;
    char s[5];
    Rectangle rec[15];
    while(scanf("%s", s) != EOF && s[0] != '*'){
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        rec[recIndex++] = Rectangle(x1, y1, x2, y2);
    }
    while(scanf("%lf%lf", &p1, &p2) && !(p1 == 9999.9 && p2 == 9999.9)){
        bool contained = false;
        for(int i=0; i<recIndex; i++){
            if(p1 > rec[i].x1 && p1 < rec[i].x2 && p2 < rec[i].y1 && p2 > rec[i].y2){
                contained = true;
                printf("Point %d is contained in figure %d\n", pointIndex, i + 1);
            }
        }
        if(!contained)
            printf("Point %d is not contained in any figure\n", pointIndex);
        pointIndex++;
    }
    return 0;
}


