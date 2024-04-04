#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int main(int argc, const char * argv[]) {
    int test = 1, keyword, excuse;
    while(scanf("%d%d", &keyword, &excuse) != EOF){
        map<string, int> m;
        string s[excuse], temp;
        for(int i=0; i<keyword; i++){
            cin >> temp;
            m[temp]++;
        }
        getchar();
        int count[excuse], maxCount = 0;
        memset(count, 0, sizeof(count));
        for(int i=0; i<excuse; i++){
            getline(cin, s[i]);
            temp = "";
            for(int j=0; j<s[i].size(); j++){
                if(isalpha(s[i][j]))
                    temp += s[i][j];
                if(!isalpha(s[i][j]) || j == s[i].size() - 1){
                    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                    if(m[temp])
                        count[i]++;
                    temp = "";
                }
            }
            maxCount = max(maxCount, count[i]);
        }
        printf("Excuse Set #%d\n", test++);
        for(int i=0; i<excuse; i++){
            if(count[i] == maxCount)
                cout << s[i] << "\n";
        }
        printf("\n");
    }
    return 0;
}

