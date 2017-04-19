#include "iostream"
#include "stdio.h"
#include "stdlib.h"
#include "string"
#include "string.h"
#include "algorithm"
#include "math.h"
#include "vector"
#include "map"
#include "queue"
#include "stack"
#include "deque"
#include "set"
using namespace std;

#define isOn(S, j) (S & (1 << j))       //To check if the j-th item of the set is on.
#define setBit(S, j) (S |= (1 << j))    //To set/turn on the j-th item (0-based indexing) of the set.
#define clearBit(S, j) (S &= ~(1 << j)) //To clear/turn oﬀ the j-th item of the set.
#define toggleBit(S, j) (S ^= (1 << j))	//To toggle (ﬂip the status of) the j-th item of the set.
#define lowBit(S) (S & (-S))            //To get the value of the least signiﬁcant bit that is on (ﬁrst from the right).
#define setAll(S, n) (S = (1 << n) - 1)	//To turn on all bits in a set of size n.

#define modulo(S, N) ((S) & (N - 1))
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

void printSet(int vS) {
    printf("S = %2d = ", vS);
    stack<int> Si;
   	while (vS) Si.push(vS % 2), vS /= 2;
    while (!Si.empty()) printf("%d", Si.top()), Si.pop();
    printf("\n");
}

int S, T;

int main() {
    printf("1. Representation (all indexing are 0-based and counted from right)\n");
    S = 34; printSet(S);
    printf("\n");

    printf("2. Multiply S by 2, then divide S by 4 (2x2), then by 2\n");
    S = 34; printSet(S);
    S = S << 1; printSet(S);
    S = S >> 2; printSet(S);
    S = S >> 1; printSet(S);
    printf("\n");

    printf("3. Set/turn on the 3-th item of the set\n");
    S = 34; printSet(S);
    setBit(S, 3); printSet(S);
    printf("\n");

    printf("4. Check if the 3-th and then 2-nd item of the set is on?\n");
    S = 42; printSet(S);
    T = isOn(S, 3); printf("T = %d, %s\n", T, T ? "ON" : "OFF");
    T = isOn(S, 2); printf("T = %d, %s\n", T, T ? "ON" : "OFF");
    printf("\n");

    printf("5. Clear/turn off the 1-st item of the set\n");
    S = 42; printSet(S);
    clearBit(S, 1); printSet(S);
    printf("\n");

    printf("6. Toggle the 2-nd item and then 3-rd item of the set\n");
    S = 40; printSet(S);
    toggleBit(S, 2); printSet(S);
    toggleBit(S, 3); printSet(S);
    printf("\n");

    printf("7. Check the first bit from right that is on\n");
    S = 40; printSet(S);
    T = lowBit(S); printf("T = %d (this is always a power of 2)\n", T);
    S = 52; printSet(S);
    T = lowBit(S); printf("T = %d (this is always a power of 2)\n", T);
    printf("\n");

    printf("8. Turn on all bits in a set of size n = 6\n");
    setAll(S, 6); printSet(S);
    printf("\n");

    printf("9. Other tricks:\n");
    printf("8 %c 4 = %d\n", '%', modulo(8, 4));
    printf("7 %c 4 = %d\n", '%', modulo(7, 4));
    printf("6 %c 4 = %d\n", '%', modulo(6, 4));
    printf("5 %c 4 = %d\n", '%', modulo(5, 4));
    printf("\n");
    printf("is %d power of 2 ? %s\n", 9, isPowerOfTwo(9) ? "YES" : "NO");
    printf("is %d power of 2 ? %s\n", 8, isPowerOfTwo(8) ? "YES" : "NO");
    printf("is %d power of 2 ? %s\n", 7, isPowerOfTwo(7) ? "YES" : "NO");
    printf("\n");

    for (int i = 0; i <= 4; i++) printf("Nearest power of 2 of %d is %d\n", i, nearestPowerOfTwo(i));
    printf("\n");
    
    printf("S = %d, turn off last bit in S, S = %d\n", 40, turnOffLastBit(40));
    printf("S = %d, turn on last zero in S, S = %d\n", 41, turnOnLastZero(41));
    printf("S = %d, turn off last consectuve bits in S, S = %d\n", 39, turnOffLastConsecutiveBits(39));
    printf("S = %d, turn on last consecutive zeroes in S, S = %d\n", 36, turnOnLastConsecutiveZeroes(36));
    printf("\n");
    return 0;
}
