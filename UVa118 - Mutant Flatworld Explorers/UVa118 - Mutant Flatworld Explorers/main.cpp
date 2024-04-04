#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int length, width, x, y, direction;
    bool fall[60][60];
    memset(fall, false, sizeof(fall));
    char c;
    string s;
    map<char, int> m;
    m['N'] = 0;
    m['E'] = 1;
    m['S'] = 2;
    m['W'] = 3;
    scanf("%d%d", &length, &width);
    while(scanf("%d %d %c", &x, &y, &c) != EOF){
        getchar();
        getline(cin, s);
        
        direction = m[c];
        bool lost = false;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'L')
                direction = (direction + 3) % 4;
            else if(s[i] == 'R')
                direction = (direction + 1) % 4;
            else if(s[i] == 'F'){
                if(direction == 0){
                    if(y + 1 > width){
                        if(!fall[y][x]){
                            fall[y][x] = true;
                            lost = true;
                            break;
                        }
                    }
                    else
                        y++;
                }
                else if(direction == 1){
                    if(x + 1 > length){
                        if(!fall[y][x]){
                            fall[y][x] = true;
                            lost = true;
                            break;
                        }
                    }
                    else
                        x++;
                }
                else if(direction == 2){
                    if(y - 1 < 0){
                        if(!fall[y][x]){
                            fall[y][x] = true;
                            lost = true;
                            break;
                        }
                    }
                    else
                        y--;
                }
                else if(direction == 3){
                    if(x - 1 < 0){
                        if(!fall[y][x]){
                            fall[y][x] = true;
                            lost = true;
                            break;
                        }
                    }
                    else
                        x--;
                }
            }
        }
        printf("%d %d ", x, y);
        if(direction == 0)
            printf("N");
        else if(direction == 1)
            printf("E");
        else if(direction == 2)
            printf("S");
        else if(direction == 3)
            printf("W");
        printf("%s", !lost ? "\n" : " LOST\n");
    }
    return 0;
}


