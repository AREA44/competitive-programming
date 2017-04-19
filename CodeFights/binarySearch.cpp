// Given a sorted array to search in and the key of the element whose index we should find, output the index of the element or -1 if it can't be found.
// Example
// * For inputArray = [1, 2, 3, 4] and searchElement = 3, the output should be
//   binarySearch(inputArray, searchElement) = 2;
// * For inputArray = [1, 2, 3, 4] and searchElement = 5, the output should be
//   binarySearch(inputArray, searchElement) = -1.

int binarySearch(std::vector<int> inputArray, int searchElement) {

  int minIndex = -1;
  int maxIndex = static_cast<int>(inputArray.size());
  int currentIndex;
  int currentElement;

  while (minIndex < maxIndex - 1) {
    currentIndex = (minIndex + maxIndex) / 2;
    currentElement =  inputArray[currentIndex] ;

    if (currentElement < searchElement) {
      minIndex = currentIndex;
    } else {
      maxIndex = currentIndex;
    }
  }

  if (maxIndex == static_cast<int>(inputArray.size())
      || inputArray[maxIndex] != searchElement) {
    return -1;
  }
  return maxIndex;
}
