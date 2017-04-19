// Find the smallest multiple of the given number that's not less than a specified lower bound.
// Example
// * For divisor = 5 and lowerBound = 12, the output should be
// minimalMultiple(divisor, lowerBound) = 15.

int minimalMultiple(int divisor, int lowerBound) {

  if (lowerBound % divisor == 0) {
    return lowerBound;
  }
  return (lowerBound / divisor + 1) * divisor;
}
