// A number is considered special, if it remains the same (and continues being a valid number) when rotated by 180°. For example, number 986 is special, but 11 or 9 aren't, because 1 ceases to be a digit after the rotation and 9 becomes 6 after the rotation.
// Determine the number of special integers between l and r, inclusive.
// Example
// For l = 8 and r = 8, the output should be
// specialNumbers(l, r) = 1;
// For l = 66 and r = 96, the output should be
// specialNumbers(l, r) = 3.

int specialNumbers(int l, int r) {

  int ans = 0;
  for (int i = l; i <= r; i++) {
    std::string digits = std::to_string(i);
    bool ok = true;
    for (int j = 0; j < (digits.size() + 1) / 2; j++) {
      if (digits[j] == '6' || digits[j] == '9') {
        ok &= digits[(int)digits.size() - 1 - j] == '9' - digits[j] + '6';
      } else if (digits[j] == '8' || digits[j] == '0') {
        ok &= digits[j] == digits[(int)digits.size() - 1 - j];
      } else {
        ok = false;
      }
    }
    if (ok) {
      ans++;
    }
  }

  return ans;
}
