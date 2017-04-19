// Two players are given an array of positive integers. They make moves one after another. During a move one should decrease exactly one element of the array by some integer. The one, after whose move the array contains a negative integer, loses.
// Who wins the game assuming both play optimally?
// Example
// * For sequence = [2], the output should be
//   nimGameNaive(sequence) = true;
// * For sequence = [2, 2], the output should be
//   nimGameNaive(sequence) = false.

bool nimGameNaive(std::vector<int> sequence) {
  for (int i = 0; i < sequence.size(); i++) {
    int tmp = sequence[i];
    for (int j = 0; j < tmp; j++) {
      sequence[i] = j;

      if (!nimGameNaive(sequence)) {
        return true;
      }
    }
    sequence[i] = tmp;
  }
  return false;
}
