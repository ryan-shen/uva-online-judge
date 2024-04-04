#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
class Node{
public:
    int ascii;
    int count;
    Node(){};
    Node(int a, int b): ascii(a), count(b){};
};

vector<Node> vec;
bool cmp(Node a, Node b){
    return (a.count < b.count) || (a.count == b.count && a.ascii > b.ascii);
}

int main(int argc, const char * argv[]) {
    char s[1001];
    int printLine = 0;
    while(cin.getline(s, 1001)){
        if(printLine++)
            printf("\n");
        vec.clear();
        int ascii[130] = {0};
        for(int i=0; i<strlen(s); i++)
            ascii[s[i]]++;
        
        for(int i=32; i<=128; i++)
            if(ascii[i])
                vec.push_back(Node(i, ascii[i]));
        
        sort(vec.begin(), vec.end(), cmp);
        for(auto it:vec)
            printf("%d %d\n", it.ascii, it.count);
    }
    return 0;
}

