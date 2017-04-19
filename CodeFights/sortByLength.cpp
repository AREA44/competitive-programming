// Given an array of strings, sort them in the order of increasing lengths.
// If two strings have the same length, their relative order must be the same as in the initial array.
// Example
// * For
// inputArray = ["abc",
//               "",
//               "aaa",
//               "a",
//               "zz"]
// the output should be
// sortByLength(inputArray) = ["",
//                             "a",
//                             "zz",
//                             "abc",
//                             "aaa"]

typedef std::vector<std::string> Array2D;

Array2D sortByLength(Array2D inputArray) {

  for (int i = 0; i < inputArray.size(); i++) {
    int minIndex = i;
    std::string tmp = inputArray[i];
    for (int j = i + 1; j < inputArray.size(); j++) {
      if (inputArray[j].size() < inputArray[minIndex].size()) {
        minIndex = j;
      }
    }
    inputArray[i] = inputArray[minIndex];
    inputArray[minIndex] = inputArray[i];
  }

  return inputArray;
}
