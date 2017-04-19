#include "iostream"
#include "stdio.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "deque"
using namespace std;

#define LSOne(S) (S & (-S))

class FenwickTree {
private:
    vector<long long> ft;
public:
    FenwickTree() {}
    FenwickTree(int n) { ft.assign(n + 4, 0); }
    long long get(int i) {
        long long sum = 0; for (; i; i -= LSOne(i)) sum += ft[i];
        return sum;
    }

    void adjust(int i, int v) {
        for (; i < (int)ft.size(); i += LSOne(i)) ft[i] += v;
    }
};

// idx   0 1 2 3 4 5 6 7  8 9 10, no index 0!
FenwickTree ft(10);     // ft = {-,0,0,0,0,0,0,0, 0,0,0}

long long rsq(int a, int b) {                              // returns RSQ(a, b)
    return ft.get(b) - (a == 1 ? 0 : ft.get(a - 1));
}

int main() {
   	ft.adjust(2, 1);        // ft = {-,0,1,0,1,0,0,0, 1,0,0}, idx 2,4,8 => +1
    ft.adjust(4, 1);        // ft = {-,0,1,0,2,0,0,0, 2,0,0}, idx 4,8 => +1
    ft.adjust(5, 2);        // ft = {-,0,1,0,2,2,2,0, 4,0,0}, idx 5,6,8 => +2
    ft.adjust(6, 3);        // ft = {-,0,1,0,2,2,5,0, 7,0,0}, idx 6,8 => +3
    ft.adjust(7, 2);        // ft = {-,0,1,0,2,2,5,2, 9,0,0}, idx 7,8 => +2
    ft.adjust(8, 1);        // ft = {-,0,1,0,2,2,5,2,10,0,0}, idx 8 => +1
    ft.adjust(9, 1);        // ft = {-,0,1,0,2,2,5,2,10,1,1}, idx 9,10 => +1
    printf("%lld\n", rsq(1, 1));  // 0 => ft[1] = 0
    printf("%lld\n", rsq(1, 2));  // 1 => ft[2] = 1
    printf("%lld\n", rsq(1, 6));  // 7 => ft[6] + ft[4] = 5 + 2 = 7
    printf("%lld\n", rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
    printf("%lld\n", rsq(3, 6));  // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1 = 6

    ft.adjust(5, 2);
    printf("%lld\n", rsq(1, 10)); // 13

    return 0;
}
