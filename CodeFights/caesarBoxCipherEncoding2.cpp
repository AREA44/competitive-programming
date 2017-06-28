// Caesar Box is a simple transposition cipher used in the Roman Empire.
// It is described as the following two-step process:
// The characters of the given message are broken into n lines of equal lengths and stacked up;
// The letters from the resulting rectangle are written from top to bottom column by column.
// Given a word, count the number of different n such that the initial message is the same as the double-encoded message.
// Example
// * For message = "abaaba", the output should be
//   caesarBoxCipherEncoding2(message) = 2.

// It is possible to apply the encoding algorithm for n = 2 or n = 3.
// * For n = 2:

// The first encoding: "abaaba" -> ab -> "aabbaa";
// aa
// ba

// The second encoding: "aabbaa" -> aa -> "abaaba".
// bb
// aa

int caesarBoxCipherEncoding2(std::string message) {
  struct Helper
  {
    std::string encode(std::string s, int n) {
      std::string res = "";
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < s.size() / n; j++) {
          res += s[j * n + i];
        }
      }
      return res;
    }
  };
  Helper h;

  int res = 0;
  int len = message.size();
  int sqrt_len = std::sqrt(len);
  for (int n = 2; n <= sqrt_len; n++) {
    if (len % n == 0) {
      if (h.encode(h.encode(message, n), n) == message) {

        if (n * n == len) {
          res += 1;
        }
        else {
          res += 2;
        }
      }
    }
  }

  return res;
}
