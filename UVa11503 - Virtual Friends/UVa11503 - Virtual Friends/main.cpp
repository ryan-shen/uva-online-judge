#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
map<string, int> name;
int parent[100001];
int Findname(string s){
    int n = name[s];
    while(parent[n] > 0)
        n = parent[n];
    return n;
}
int main(int argc, const char * argv[]) {
    int test, n;
    scanf("%d", &test);
    while(test--){
        scanf("%d", &n);
        name.clear();
        string s1, s2;
        int index = 1;
        for(int i=1; i<=n; i++)
            parent[i] = -1;
        for(int i=0; i<n; i++){
            cin >> s1 >> s2;
            if(!name[s1])
                name[s1] = index++;
            if(!name[s2])
                name[s2] = index++;
            if(s1.compare(s2) && Findname(s1) != Findname(s2)){
                if(parent[Findname(s1)] > parent[Findname(s2)]){
                    parent[Findname(s2)] += parent[Findname(s1)];
                    parent[Findname(s1)] = Findname(s2);
                    printf("%d\n", abs(parent[Findname(s2)]));
                }
                else{
                    parent[Findname(s1)] += parent[Findname(s2)];
                    parent[Findname(s2)] = Findname(s1);
                    printf("%d\n", abs(parent[Findname(s1)]));
                }
            }
            else
                printf("%d\n", abs(parent[Findname(s1)]));
        }
    }
    return 0;
}

