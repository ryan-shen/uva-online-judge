#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, maxN = 10000, humbleTable[maxN];
    set<long long> st;
    st.insert(1);
    for(auto it=st.begin(); it!=st.end(); it++){
        long long t = *it;
        if(t * 2 > 0 && t * 2 <= 2000000000)
            st.insert(t * 2);
        if(t * 3 > 0 && t * 3 <= 2000000000)
            st.insert(t * 3);
        if(t * 5 > 0 && t * 5 <= 2000000000)
            st.insert(t * 5);
        if(t * 7 > 0 && t * 7 <= 2000000000)
            st.insert(t * 7);
    }
    auto it = st.begin();
    for(int i=1; i<=5842; i++){
        humbleTable[i] = *it;
        it++;
    }
    
    while(scanf("%d", &n) != EOF && n != 0){
        printf("The %d", n);
        if(n % 10 == 1 && n % 100 != 11)
            printf("st");
        else if(n % 10 == 2 && n % 100 != 12)
            printf("nd");
        else if(n % 10 == 3 && n % 100 != 13)
            printf("rd");
        else
            printf("th");
        printf(" humble number is %d.\n", humbleTable[n]);
    }
    return 0;
}

