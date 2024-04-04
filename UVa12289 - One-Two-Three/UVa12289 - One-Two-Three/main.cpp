#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    string s;
    scanf("%d", &test);
    while(test--){
        cin >> s;
        if(s.size() == 5)
            printf("3\n");
        else{
            int one = 0, two = 0;
            if(s[0] == 'o')
                one++;
            if(s[1] == 'n')
                one++;
            if(s[2] == 'e')
                one++;
            if(s[0] == 't')
                two++;
            if(s[1] == 'w')
                two++;
            if(s[2] == 'o')
                two++;
            printf("%s\n", one > two ? "1" : "2");
        }
    }
    return 0;
}
