// Given array of integers, check whether each integer, that occurs in it, is contained there the same number of times as any other integer from the given array.
// Example
// * For inputArray = [1, 2, 2, 1], the output should be
// checkEqualFrequency(inputArray) = true;
// * For inputArray = [1, 2, 2, 3, 1, 3, 1, 3], the output should be
// checkEqualFrequency(inputArray) = false.

bool checkEqualFrequency(std::vector<int> inputArray) {
    int numberOfEqual = 1;
    sort(inputArray.begin(),inputArray.end());
    while (numberOfEqual < inputArray.size() && inputArray[numberOfEqual - 1] == inputArray[numberOfEqual]) {
      numberOfEqual++;
    }
    for (int i = 0; i < inputArray.size(); i += numberOfEqual) {
        if (inputArray[i] == inputArray[i - 1]) {
            return false;
        }
        for (int j = i+1; j < i + numberOfEqual; j++) {
            if (inputArray[j] != inputArray[j - 1]) {
                return false;
            }
        }
    }
    return true;
}
