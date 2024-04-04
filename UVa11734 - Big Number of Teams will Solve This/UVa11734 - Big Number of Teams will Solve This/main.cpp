#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int test;
    string team, judge;
    char ch;
    scanf("%d", &test);
    getchar();
    for(int k=1; k<=test; k++){
        printf("Case %d: ", k);
        team = "";
        bool wrongFormat = false;
        while(scanf("%c", &ch) != EOF && ch != '\n'){
            if(ch == ' '){
                wrongFormat = true;
                continue;
            }
            else
                team += ch;
        }
        getline(cin, judge);
        if(team.compare(judge))
            printf("Wrong Answer\n");
        else if(wrongFormat)
            printf("Output Format Error\n");
        else
            printf("Yes\n");
    }
    return 0;
}

