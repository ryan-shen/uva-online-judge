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
    string s;
    int n;
    Node(){};
    Node(string a, int b): s(a), n(b){};
};
int main(int argc, const char * argv[]) {
    int test, n;
    string s;
    scanf("%d", &test);
    for(int k=1; k<=test; k++){
        vector<Node> vec;
        int maxValue = 0;
        for(int i=0; i<10; i++){
            cin >> s >> n;
            vec.push_back(Node(s, n));
            maxValue = max(maxValue, n);
        }
        printf("Case #%d:\n", k);
        for(auto i: vec){
            if(i.n == maxValue)
                cout << i.s << '\n';
        }
    }
    return 0;
}
