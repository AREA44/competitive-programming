// A function that sums the elements of the given array.
// Example
// * For inputArray = [1, 3, 2, 10], the output should be
// arrayElementsSum(inputArray) = 16.

int arrayElementsSum(std::vector<int> inputArray) {

  int result = 0;

  for (int i = 0; i < inputArray.size(); i++) {
    result += inputArray[i];
  }
  return result;
}
