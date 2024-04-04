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
    int a;
    int b;
    Node(int a, int b): a(a), b(b){};
};
int main(int argc, const char * argv[]) {
    int n;
    vector<Node> vec[5];
    for(int k=1; k<=4; k++){
        int limit = pow(10, k);
        for(int i=0; i<limit; i++){
            for(int j=0; j<limit; j++){
                int a = (i + j) * (i + j) / limit;
                int b = (i + j) * (i + j) % limit;
                if(i == a && j == b)
                    vec[k].push_back(Node(i, j));
            }
        }
    }
    while(scanf("%d", &n) != EOF){
        for(auto i: vec[n / 2])
            printf("%0*d%0*d\n", n / 2, i.a, n / 2, i.b);
    }
    return 0;
}


