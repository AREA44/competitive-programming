// Given an array of integers, find its minimal element.
// Example
// * For inputArray = [19, 32, 11, 23], the output should be
//   arrayMinimum(inputArray) = 11.

int arrayMinimum(std::vector<int> inputArray) {

  int indexOfMinimum = 0;
  for (int i = 1; i < inputArray.size(); i++) {
    if (inputArray[i] < inputArray[indexOfMinimum]) {
      indexOfMinimum = i;
    }
  }
  return  inputArray[indexOfMinimum] ;
}
