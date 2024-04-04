#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int test;
    scanf("%d", &test);
    while (test--) {
        int m, d;
        int count = 4;
        scanf("%d%d", &m, &d);
        for(int i=1; i<m; i++)
            count += month[i];
        count += d;
        cout << week[count % 7] << endl;
    }
    return 0;
}
