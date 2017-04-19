// For each integer from 1 to n find the maximal power P of the given divisor such that divisorP divides the current number.
// The algorithm should return the sum of those powers.
// Example
// * For n = 6 and divisor = 2, the output should be
// sumOfPowers(n, divisor) = 4.
// Explanation: 0 + 1 + 0 + 2 + 0 + 1 = 4.

int sumOfPowers(int n, int divisor) {
  int s = 0;
  for (int i = 1; i <= n; i++) {
    int u = 1;
    int c = 0;
    while (true) {
      u *= divisor;
      if (i % u != 0) break;
      c++;
    }
    s += c;
  }
  return s;
}
