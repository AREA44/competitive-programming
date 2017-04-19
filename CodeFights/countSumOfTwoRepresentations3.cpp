// Given integers n, l and r, find the number of ways to represent n as a sum of two integers A and B such that l ≤ A ≤ B ≤ r.
// Example
// * For n = 6, l = 2 and r = 4, the output should be
// countSumOfTwoRepresentations3(n, l, r) = 2.

int countSumOfTwoRepresentations3(int n, int l, int r) {
    int result = 0;
    for (int i = 1; i <= n - i; i++) {
        if (l <= i && n - i <= r) {
            result++;
        }
    }
    return result;
}
