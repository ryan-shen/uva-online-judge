#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char a[1001], b[1001];
    while(cin.getline(a, 1001)){
        cin.getline(b, 1001);
        int lena = strlen(a);
        int lenb = strlen(b);
        int lcs[lena + 1][lenb + 1];
        memset(lcs, 0, sizeof(lcs));
        for(int i=1; i<=lena; i++){
            for(int j=1; j<=lenb; j++){
                if(a[i - 1] == b[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        printf("%d\n", lcs[lena][lenb]);
    }
    return 0;
}

