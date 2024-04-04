#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    map<string, int> map;
    int test;
    scanf("%d", &test);
    while(test--){
        char temp[100];
        string country;
        cin >> country; //scanf 不支援 c++ 的 string
        cin.getline(temp, 100); //吃掉空白後面一整行，並吃掉換行符號
        map[country]++; //key 不存在時值為零
    }
    for(auto it: map)
        cout << it.first << " " << it.second << endl;
    return 0;
}

