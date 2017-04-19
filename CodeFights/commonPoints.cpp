// Given integers l1, r1, l2 and r2, count integers x such that l1 < x < r1 and l2 < x < r2.
// Example
// * For l1 = 1, r1 = 5, l2 = 2 and r2 = 10, the output should be
//   commonPoints(l1, r1, l2, r2) = 2.

int commonPoints(int l1, int r1, int l2, int r2) {
  int result = std::min(r1, r2) - std::max(l1, l2) - 1;
  if (result < 0) {
    result = 0;
  }
  return result;
}
