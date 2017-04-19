// Find the sum of all positive integers that can NOT be written in the form a * p + b * q, where p and q are given different prime numbers, and a and b are some non-negative integers.
// Example
// For p = 3 and q = 5, the output should be
// specificSum(p, q) = 14.
// Explanation: 1 + 2 + 4 + 7 = 14.

int specificSum(int p, int q) {
  int result = 0, apbqValue = 1, lastIncorrect = -1;

  while (apbqValue - lastIncorrect <= q) {
    int a = 0, correct = false;
    while (a * p <= apbqValue) {
      if ((apbqValue - a * p) % q == 0) {
        correct = true;
      }
      a++;
    }
    if (!correct) {
      result += apbqValue;
      lastIncorrect = apbqValue;
    }
    apbqValue++;
  }

  return result;
}
