// Determine if the given character is a digit or not.
// Example
// * For symbol = '9', the output should be
//   isDigit(symbol) = true;
// * For symbol = '-', the output should be
//   isDigit(symbol) = false.

bool isDigit(char symbol) {
    if('0'<=symbol&&symbol<='9') return true;
    return false;
}
