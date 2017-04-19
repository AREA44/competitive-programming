// Given a string, check if a palindrome can be obtained from it by at most one swap of some pair of characters.
// Example
// * For inputString = "aabaa", the output should be
// isOneSwapEnough(inputString) = true.
// It is already a palindrome.

// * For inputString = "abab", the output should be
// isOneSwapEnough(inputString) = true.
// For example, one can swap the leftmost 'a' with the leftmost 'b'.

// * For inputString = "abc", the output should be
// isOneSwapEnough(inputString) = false.

bool isOneSwapEnough(std::string inputString) {

  std::vector<std::vector<char>> badPairs(2);
  int badPairsCnt = 0;
  for (int i = 0; i < (int)inputString.size() / 2; i++) {
    char a = inputString[i];
    char b = inputString[inputString.size() - i - 1];
    if (a != b) {
      if (badPairsCnt == 2) {
        return false;
      }
      if (a > b) {
        swap(a, b);
      }
      badPairs[badPairsCnt++] = {a, b};
    }
  }
  if (badPairsCnt == 0) {
    return true;
  } else if (badPairsCnt == 1) {
    if (inputString.size() % 2 == 0) {
      return false;
    }
    char c = inputString[inputString.size() / 2];
    return badPairs[0][0] == c || badPairs[0][1] == c;
  } else {
    return badPairs[0][0] == badPairs[1][0] && badPairs[0][1] == badPairs[1][1];
  }
}
