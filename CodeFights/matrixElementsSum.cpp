// In a rectangular matrix of integers, call an element top-zero-free if on top of that element (in the same column) there are no 0s. Find the sum of all top-zero-free elements.
// Example
// For
// matrix = [[0, 1, 1, 2], 
//           [0, 5, 0, 0], 
//           [2, 0, 3, 3]]
// the output should be
// matrixElementsSum(matrix) = 9.
// Explanation: The answer is 1 + 5 + 1 + 2 = 9.

int matrixElementsSum(std::vector<std::vector<int>> matrix) {

  int result = 0;
  for (int i = 0; i < matrix[0].size(); i++) {
    for (int j = 0; j < matrix.size(); j++) {
      if (matrix[j][i] == 0) {
        break;
      }
      result +=  matrix[j][i] ;
    }
  }

  return result;
}
