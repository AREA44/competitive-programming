// Given a base for a numeral system, an integer number can be represented as an array of its digits with the most significant digit being on the first place, each digit is stored as an integer from 0 to base - 1.
// Leading zeros must be omitted.
// Example
// * For base = 10, a = [9, 8, 7, 6] and b = [7, 6, 5], the output should be
// multiplicationOfBigNumbers(base, a, b) = [7, 5, 5, 5, 1, 4, 0].
// Number a in numeral system 10 is equal to 9 * 103 + 8 * 102 + 7 * 101 + 6 * 100 = 9876.
// Number b in numeral system 10 is equal to 7 * 102 + 6 * 101 + 5 * 100 = 765.
// 9876 * 765 = 7555140, so the answer is [7, 5, 5, 5, 1, 4, 0].

std::vector<int> multiplicationOfBigNumbers(int base, std::vector<int> a, std::vector<int> b) {

  std::vector<int> c;
  int next = 0;
  for (int k = 0; k < a.size() + b.size() - 1; k++) {
    int cur = next;
    int i, j;
    if (k < a.size()) {
      i = (int)a.size() - 1 - k;
      j = (int)b.size() - 1;
    } else {
      i = 0;
      j = (int)a.size() + (int)b.size() - 2 - k;
    }
    while (i < a.size() && j >= 0) {
      cur += a[i] * b[j];
      i++;
      j--;
    }
    c.push_back(cur % base);
    next = cur / base;
  }
  if (next > 0) {
    c.push_back(next);
  }

  std::reverse(c.begin(), c.end());
  return c;
}
