// Given an integer n, find the difference between the sums of its even and odd digits.
// Example
// * For n = 412, the output should be
// digitSumsDifference(n) = 5;
// * For n = 1203, the output should be
// digitSumsDifference(n) = -2.

int digitSumsDifference(int n) {
    int result = 0;
    while (n) {
        if ((n%10) % 2 == 1) result -= n%10;
        else result += n%10;
        n /= 10;
    }
    return result;
}
