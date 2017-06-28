// K-subsets Removal
// Time limit: 1000 ms
// Memory limit: 128 MB

// You are given an array of N integers. On this array you should perform the following type of operation: choose K equal elements and remove them from the array. You have to perform operations as long as it is possible. In the end you are asked to find the most frequent element.

// Standard input
// The first line contains two integers N and K.
// The second line contains NN integers representing the elements of the array.

// Standard output
// Output a single integer representing the highest frequency of an element in the final array.

// Constraints and notes
// 1 <= K <= N <= 1000
// The elements of the array are integers between 1 and 1000
// Input	                          Output	            Explanation
// 5                                   1                     We can perform only one operation: remove two elements equal to 3.
// 3 3 3 1 2                                                 So in the end each distinct value has a frequency of 1.

// 6                                   3                     The array becomes empty, so the answer is 0.
// 2 3 2 3 3 2

// 12                                  2                     We remove two subsets of 44s and one subset of 33s.
// 4 3 4 3 4 4 4 3 3 4 4 3

#include <bits/stdc++.h>
using namespace std;

int N, K, inputArray[1001], input, result;

int main() {
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++){
        scanf("%d",&input);
        inputArray[input]++;
    }
    for(int i=1;i<=N;i++){
        if(inputArray[i]!=0)
            result=max(result,inputArray[i]%K);
    }
    printf("%d\n",result);
    return 0;
}
