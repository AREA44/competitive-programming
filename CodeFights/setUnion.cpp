// Apply union operation to the given sets of integers.
// Sets may contain duplicate elements.
// Example
// * For A = [1, 1] and B = [1, 1, 1], the output should be
// setUnion(A, B) = [1, 1, 1].

std::vector<int> setUnion(std::vector<int> A, std::vector<int> B) {

  int pos_b = 0;

  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());
  std::vector<int> C;

  for (int pos_a = 0; pos_a < A.size(); pos_a++) {
    while (pos_b < B.size() && B[pos_b] < A[pos_a]) {
      C.push_back(B[pos_b]);
      pos_b++;
    }
    C.push_back(A[pos_a]);
    if (A[pos_a] == B[pos_b]) {
      pos_b++;
    }
  }
  while (pos_b < B.size()) {
    C.push_back(B[pos_b]);
    pos_b++;
  }

  return C;
}
