// Given an array of 2k integers (for some integer k), perform the following operations until the array contains only one element:
// 1. On the 1st, 3rd, 5th, etc. iterations (1-based) replace each pair of consecutive elements with their sum;
// 2. On the 2nd, 4th, 6th, etc. iterations replace each pair of consecutive elements with their product.
// After the algorithm has finished, there will be a single element left in the array. Return that element.
// Example
// * For inputArray = [1, 2, 3, 4, 5, 6, 7, 8], the output should be
// arrayConversion(inputArray) = 186.
// We have [1, 2, 3, 4, 5, 6, 7, 8] -> [3, 7, 11, 15] -> [21, 165] -> [186], so the answer is 186.

int arrayConversion(std::vector<int> inputArray) {
  int operation = 1;
  while (inputArray.size() > 1) {
    std::vector<int> newArray;
    for (int i = 0; i < inputArray.size(); i += 2) {
      if (operation % 2 == 1) {
        newArray.push_back(inputArray[i] + inputArray[i + 1]);
      } else {
        newArray.push_back(inputArray[i] * inputArray[i + 1]);
      }
    }
    inputArray = newArray;
    operation++;
  }
  return inputArray[0];
}
