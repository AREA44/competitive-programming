// You have a string consisting of zeros, ones and asterisks (*). Consider the following operation:
// Choose any two adjacent positions in the string;
// If one of them is 0, and the other one is 1, remove these two digits from the string.
// Find the length of the smallest string that can be obtained after applying this operation multiple times.
// Example
// * For s = "01010", the output should be
// zerosAndOnes(s) = 1;

// * For s = "111000", the output should be
// zerosAndOnes(s) = 0;

// * For s = "111*000", the output should be
// zerosAndOnes(s) = 7.

int zerosAndOnes(std::string s) {
  int answer = s.size();
  std::vector<char> st;
  int topElem = -1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '*') {
      st.clear();
      topElem = -1;
    } else {
      if (topElem >= 0 && st[topElem] != s[i]) {
        topElem--;
        answer-=2;
      } else {
        if (topElem + 1 < st.size()) {
          st[++topElem] = s[i];
        } else {
          topElem++;
          st.push_back(s[i]);
        }
      }
    }
  }
  return answer;
}
