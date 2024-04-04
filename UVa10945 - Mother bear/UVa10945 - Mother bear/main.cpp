#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    char s[1000];
    while(cin.getline(s, 1000)){
        if(s[0] == 'D' && s[1] == 'O' && s[2] == 'N' && s[3] == 'E')
            break;
        int left = 0;
        int right = strlen(s) - 1;
        bool pass = true;
        while(left <= right){
            if(!isalpha(s[left]))
                left++;
            else if(!isalpha(s[right]))
                right--;
            else if(tolower(s[left]) == tolower(s[right])){
                left++;
                right--;
            }
            else{
                pass = false;
                break;
            }
        }
        if(pass)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
    return 0;
}

