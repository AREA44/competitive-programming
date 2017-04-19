// Triangular Numbers are positive integers that can be represented as a sum of all integers from 1 up to some n. Determine if the given number is Triangular.
// Example
// * For value = 10, the output should be
// isSum(value) = true.
// Explanation: 10 = 1 + 2 + 3 + 4.

// * For value = 11, the output should be
// isSum(value) = false.
// 1 + 2 + 3 + 4 = 10 < value < 15 = 1 + 2 + 3 + 4 + 5.

bool isSum(int value) {
    int sum=0,
        cnt=1;
    while(sum<value){
        sum+=cnt;
        cnt++;
    }
    if(sum==value)
        return true;
    return false;
}

