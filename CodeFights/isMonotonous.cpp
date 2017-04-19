// Given array of integers, check if it represents either a strictly increasing or a strictly decreasing sequence.
// Example
// * For sequence = [1, 4, 5, 7, 9], the output should be
// isMonotonous(sequence) = true;
// * For sequence = [0], the output should be
// isMonotonous(sequence) = true;
// * For sequence = [3, 3], the output should be
// isMonotonous(sequence) = false.

bool isMonotonous(std::vector<int> sequence) {
  if (sequence.size() == 1) {
    return true;
  }
  int direction = sequence[1] - sequence[0];
  for (int i = 0; i < (int)sequence.size() - 1; i++) {
    if (direction * (sequence[i + 1] - sequence[i]) <= 0) {
      return false;
    }
  }
  return true;
}
