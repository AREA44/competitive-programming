// Some file managers sort filenames taking into account case of the letters, others compare strings as if all of the letters are of the same case. That may lead to different ways of filename ordering.
// Call two filenames an unstable pair if their ordering depends on the case.
// To compare two filenames a and b, find the first position i at which a[i] ≠ b[i]. If a[i] < b[i], then a < b. Otherwise a > b. If such position doesn't exist, the shorter string goes first.
// Given two filenames, check whether they form an unstable pair.
// Example
// * For filename1 = "aa" and filename2 = "AAB", the output should be
// isUnstablePair(filename1, filename2) = true.
// Because "AAB" < "aa", but "AAB" > "AA".

// * For filename1 = "A" and filename2 = "z", the output should be
// isUnstablePair(filename1, filename2) = false.
// Both "A" < "z" and "a" < "z".

bool isUnstablePair(std::string filename1, std::string filename2) {

  struct Helper {
    bool compare(std::string filename1, std::string filename2) {
      int len = std::min(filename1.size(), filename2.size());
      for (int i = 0; i < len; i++) {
        if (filename1[i] < filename2[i]) {
          return true;
        }
        if (filename2[i] < filename1[i]) {
          return false;
        }
      }
      if (filename1.size() < filename2.size()) {
        return true;
      }
      return false;
    }

    std::string toLowercase(std::string filename) {
      std::string lowercased = "";
      for (int i = 0; i < filename.size(); i++) {
        if ('A' <= filename[i] && filename[i] <= 'Z') {
          lowercased += char(int(filename[i]) - int('A') + int('a'));
        }
        else {
          lowercased += filename[i];
        }
      }
      return lowercased;
    }
  };

  Helper h;
  bool firstComparison = h.compare(filename1, filename2);
  filename1 = h.toLowercase(filename1);
  filename2 = h.toLowercase(filename2);

  if (firstComparison != h.compare(filename1, filename2)) {
    return true;
  }
  return false;
}
