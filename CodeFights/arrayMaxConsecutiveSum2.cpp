// Given an array of integers, find the maximum possible sum of its contiguous subarrays.
// The subarray must contain at least 1 element.
// Example
// * For inputArray = [-2, 2, 5, -11, 6], the output should be
// arrayMaxConsecutiveSum2(inputArray) = 7.

int arrayMaxConsecutiveSum2(std::vector<int> inputArray) {

  int currentSum = 0,
      currentMinimalSum = 0,
      result =  -1e9 ;

  for (int i = 0; i < inputArray.size(); i++) {
    currentSum += inputArray[i];
    if (currentSum - currentMinimalSum > result) {
      result = currentSum - currentMinimalSum;
    }
    if (currentSum < currentMinimalSum) {
      currentMinimalSum = currentSum;
    }
  }

  return result;
}
