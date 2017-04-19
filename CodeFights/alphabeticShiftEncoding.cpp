// Consider the "circular" alphabet. It is the same as the ordinary one but 'z' is followed by 'a'.
// In such an alphabet one can define a k-shift for any 0 ≤ k < 26. Applying such a shift will change each letter of the string with a letter that comes exactly k letters after. For instance, 3-shift will change 'a' to 'd' and 'y' to 'b'.
// Given an initial string and its k-shift (for some unknown k) with some mistakes (a mistake means that a character was shifted incorrectly), find the minimal possible number of mistakes.
// Example
// * For inputString = "xyza" and encodedString = "abdd", the output should be
// alphabeticShiftEncoding(inputString, encodedString) = 1;
// * For inputString = "aw" and encodedString = "aw", the output should be
// alphabeticShiftEncoding(inputString, encodedString) = 0.

int alphabeticShiftEncoding(std::string inputString, std::string encodedString) {

  int result = inputString.size();
  for (int i = 0; i < inputString.size(); i++) {
    int mistakes = 0,
        k = encodedString[i] - inputString[i];
    if (k < 0) {
      k += 26;
    }
    for (int j = 0; j < inputString.size(); j++) {
      if ((inputString[j] - 'a' + k) % 26 !=
           encodedString[j] - 'a') {
        mistakes++;
      }
    }
    result = std::min(mistakes, result);
  }
  return result;
}
