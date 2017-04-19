// For a given array of distinct integers find the maximum number of its elements that belong to some arithmetic progression with integer absolute difference between consecutive elements more than 1.
// Example
// * For inputArray = [1, 3, 2, 5, -7], the output should be
// subsetForArithmeticProgression(inputArray) = 4.
// Elements -7, 1, 3 and 5 belong to the arithmetic progression ..., -7, -5, -3, -1, 1, 3, 5, ....

int subsetForArithmeticProgression(std::vector<int> inputArray) {

  int result = 1;

  for (int i = 0; i < inputArray.size(); i++) {
    for (int j = i + 1; j < inputArray.size(); j++) {
      int dif = std::abs(inputArray[i] - inputArray[j]);
      for (int divisor = 1; divisor * divisor <= dif; divisor++) {
        if (dif % divisor == 0) {
          int cnt = 0;
          int pair_divisor = dif / divisor;

          if (divisor > 1) {
            for (int k = 0; k < inputArray.size(); k++) {
              if (std::abs(inputArray[i] - inputArray[k]) % divisor == 0) {
                cnt++;
              }
            }
            result = std::max(result, cnt);
          }

          cnt = 0;
          if (pair_divisor > 1) {
            for (int k = 0; k < inputArray.size(); k++) {
              if (std::abs(inputArray[i] - inputArray[k]) % pair_divisor == 0) {
                cnt++;
              }
            }
            result = std::max(result, cnt);
          }
        }
      }
    }
  }

  return result;
}
