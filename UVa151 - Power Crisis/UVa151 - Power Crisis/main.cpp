#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    while(scanf("%d", &n) != EOF && n != 0){
        int m = 1;
        bool pass = false;
        while(true){
            vector<int> vec;
            for(int i=2; i<=n; i++){
                vec.push_back(i);
            }
            int cycle = 1; //循環中的第幾個數
            auto it = vec.begin();
            while(true){
                if(cycle == m){
                    vec.erase(it);
                    if(it == vec.end())
                        it = vec.begin();
                    cycle = 1;
                    if(vec.size() == 1){
                        if(vec.front() == 13){
                            pass = true;
                            printf("%d\n", m);
                        }
                        break;
                    }
                }
                else{
                    if(++it == vec.end())
                        it = vec.begin();
                    cycle++;
                }
            }
            if(pass)
                break;
            m++;
        }
    }
    return 0;
}

