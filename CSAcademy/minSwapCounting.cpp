// Min Swap Counting
// Time limit: 1000 ms
// Memory limit: 128 MB

// You are given an array of size N where each element is either 0 or 1. You are allowed to swap any two adjacent elements. Find the minimum number of swaps needed to sort the entire array.

// Standard input
// The first line contains a single integer N.
// The second line contains NN integers representing the elements of the array. Each integer is equal to 0 or 1.

// Standard output
// Output a single integer representing the minimum number of swaps needed to sort the array.

// Constraints and notes
// 1 <= N <= 5*10^4

// Input	          Output
// 5                4
// 1 0 1 1 0

// 3                0
// 0 1 1

// 5                3
// 1 1 1 0 1

#include <bits/stdc++.h>
using namespace std;

int N,input,result;
queue<int> q;

int main() {
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&input);
        if(input==0) q.push(i);
    }
    int curNext=0;
    while(!q.empty()){
        result+=q.front()-curNext;
        curNext++;
        q.pop();
    }
    printf("%d\n",result);
    return 0;
}
