#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
class Figure{
public:
    char type;
    double x1;
    double x2;
    double y1;
    double y2;
    double r;
    Figure(){};
    Figure(char ch, double a, double b, double c, double d): type(ch), x1(a), y1(b), x2(c), y2(d){};
    Figure(char ch, double a, double b, double c): type(ch), x1(a), y1(b), r(c){};
};
int main(int argc, const char * argv[]) {
    int index = 0, pointIndex = 1;
    double x1, x2, y1, y2, p1, p2, r;
    char s[5];
    Figure fig[15];
    while(scanf("%s", s) != EOF && s[0] != '*'){
        if(s[0] == 'r'){
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            fig[index++] = Figure('r', x1, y1, x2, y2);
        }
        else if(s[0] == 'c'){
            scanf("%lf%lf%lf", &x1, &y1, &r);
            fig[index++] = Figure('c', x1, y1, r);
        }
    }
    while(scanf("%lf%lf", &p1, &p2) && !(p1 == 9999.9 && p2 == 9999.9)){
        bool contained = false;
        for(int i=0; i<index; i++){
            if(fig[i].type == 'r'){
                if(p1 > fig[i].x1 && p1 < fig[i].x2 && p2 < fig[i].y1 && p2 > fig[i].y2){
                    contained = true;
                    printf("Point %d is contained in figure %d\n", pointIndex, i + 1);
                }
            }
            else if(fig[i].type == 'c'){
                if(sqrt(pow(p1 - fig[i].x1, 2) + pow(p2 - fig[i].y1, 2)) < fig[i].r){
                    contained = true;
                    printf("Point %d is contained in figure %d\n", pointIndex, i + 1);
                }
            }
        }
        if(!contained)
            printf("Point %d is not contained in any figure\n", pointIndex);
        pointIndex++;
    }
    return 0;
}



