#include "iostream"
#include "stdio.h"
using namespace std;

const int MaxN=1e4+4;

int n,key;
int a[MaxN];

int binarysearch(int a[], int key){
    int start = 1,end=n,mid=(start+end)/2;
    while (start <= end&&a[mid] != key){
        if (a[mid] < key) start = mid + 1;
        else end = mid - 1;
        mid = (end + start) / 2;
    }
    if (a[mid] == key) return mid;
    else return -1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &key);
    if (binarysearch(a, key) != -1) printf("%d\n", binarysearch(a, key));
    else printf("Not found\n");
    return 0;
}
