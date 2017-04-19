//Given array of integers inputArray, construct an array of arrays of integers answer such that
// answer is of the same length as inputArray;
// for each valid i the ith element of answer is an array of exactly two integers;
// 0 ≤ answer[i][j] < inputArray.length;
// answer[i][0] ≤ i ≤ answer[i][1];
// inputArray[i] is the minimum value among all the elements of inputArray at positions from answer[i][0] up to answer[i][1], inclusive;
// for each valid i, answer[i][1] - answer[i][0] has the maximum possible value.
// Example
// For inputArray = [3, -2, 1, -2, -4], the output should be
// neighborhoodForMinimum(inputArray) = [[0, 0],
//                                       [0, 3],
//                                       [2, 2],
//                                       [0, 3],
//                                       [0, 4]]

typedef std::vector<std::vector<int>> matrix;

matrix neighborhoodForMinimum(std::vector<int> inputArray) {

  matrix answer;
  for (int i = 0; i < inputArray.size(); i++) {
    std::vector<int> borders;
    int j = i;
    while (j >= 0 && inputArray[i] <= inputArray[j]) {
      j--;
    }
    borders.push_back(j + 1);
    j = i;
    while (j < inputArray.size() && inputArray[i] <= inputArray[j]) {
      j++;
    }
    borders.push_back(j - 1);
    answer.push_back(borders);
  }
  return answer;
}
