#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    vector<int> fib[5000];
    for(int i=0; i<5000; i++)
        fib[i].clear();
    vector<int>::iterator it;
    fib[1].push_back(1);
    fib[2].push_back(1);
    for(int i=3; i<5000; i++){
        for(int j=0; j<fib[i - 1].size(); j++){
            int temp;
            if(j < fib[i - 2].size())
                temp = fib[i - 1].at(j) + fib[i - 2].at(j);
            else
                temp = fib[i - 1].at(j);
            if(j >= fib[i].size())
                fib[i].push_back(temp);
            else{
                it = fib[i].begin() + j;
                (*it) += temp;
            }
            //對 it 修改值後要再重新定位一次，不然會錯
            it = fib[i].begin() + j;
            if((*it) >= 10){
                temp = (*it) / 10;
                (*it) = (*it) % 10;
                fib[i].push_back(temp);
            }
        }
    }
    while(scanf("%d", &n) != EOF){
        for(auto it=fib[n].rbegin(); it!=fib[n].rend(); it++)
            cout << *it;
        cout << endl;
    }
    return 0;
}

