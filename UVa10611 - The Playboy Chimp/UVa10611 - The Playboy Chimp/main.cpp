#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int arr[50005];
int q;
int BinarySearch1(int left, int right){
    int mid = (left + right) / 2;
    if((arr[mid] < q && arr[mid + 1] >= q) || left + 1 == right)
        return arr[mid];
    else if(arr[mid] < q && arr[mid + 1] < q)
        return BinarySearch1(mid, right);
    else
        return BinarySearch1(left, mid);
}
int BinarySearch2(int left, int right){
    int mid = (left + right) / 2;
    if((arr[mid] > q && arr[mid - 1] <= q) || left + 1 == right)
        return arr[mid];
    else if(arr[mid] > q && arr[mid - 1] > q)
        return BinarySearch2(left, mid);
    else
        return BinarySearch2(mid, right);
}
int main(int argc, const char * argv[]) {
    int n, query;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &query);
    for(int k=0; k<query; k++){
        scanf("%d", &q);
        int left = BinarySearch1(0, n);
        int right = BinarySearch2(0, n);
        if(left >= q)
            printf("X %d\n", right);
        else if(right <= q)
            printf("%d X\n", left);
        else if(left >= q && right <= q)
            printf("X X\n");
        else
            printf("%d %d\n", left, right);
    }
    return 0;
}

