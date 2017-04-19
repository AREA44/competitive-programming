// Given an reduced improper fraction output it as an reduced mixed fraction.
// Example
// * For A = [7, 2], the output should be
// improperFractionToMixed(A) = [3, 1, 2].
// Explanation: 7/2 = 3 + 1/2.

std::vector<int> improperFractionToMixed(std::vector<int> A) {

  std::vector<int> B(3);
  B[0] = A[0] / A[1], B[1] = 0, B[2] = 0;
  B[1] = A[0] - A[1] * B[0];
  B[2] = A[1];

  return B;
}
