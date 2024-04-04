#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int test, n;
    string s;
    char c;
    scanf("%d", &test);
    getchar();
    for(int k=1; k<=test; k++){
        if(k > 1) printf("\n");
        getchar();
        stringstream ss;
        vector<int> vec;
        getline(cin, s);
        ss << s;
        while(ss >> n)
            vec.push_back(n);
        
        string arr[vec.size()];
        int index = 0;
        while(cin >> s){
            scanf("%c", &c);
            arr[*(vec.begin()+index) - 1] = s;
            index++;
            if(c == '\n')
                break;
        }
            
        
        for(int i=0; i<vec.size(); i++)
            cout << arr[i] << '\n';
    }
    return 0;
}
