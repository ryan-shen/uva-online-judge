#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, test = 1;
    char s[200];
    while(scanf("%d", &n) != EOF && n != 0){
        cin.getline(s, 200);
        printf("Case %d:\n", test++);
        printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");
        for(int i=0; i<n; i++){
            cin.getline(s, 200);
            printf("printf(\"");
            for(int j=0; j<strlen(s); j++){
                if(s[j] == '"' || s[j] == '\\')
                    printf("\\");
                printf("%c", s[j]);
            }
            printf("\\n\");\n");
        }
        printf("printf(\"\\n\");\nreturn 0;\n}\n");
    }
    return 0;
}

