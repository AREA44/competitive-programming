// Find the smallest integer that is divisible by all integers on a given interval [left, right].
// Example
// * For left = 2 and right = 4, the output should be
// smallestMultiple(left, right) = 12.

int smallestMultiple(int left, int right) {

  for (int candidate = 1; ; candidate++) {
    int correct = true;
    for (int divisor = left; divisor <= right; divisor++) {
      if (candidate % divisor) {
        correct = false;
        break;
      }
    }
    if (correct) {
      return candidate;
    }
  }
}
