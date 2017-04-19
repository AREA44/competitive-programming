// We need a function that calculates the number of Sundays after a specific day for a given period.
// Example
// * For n = 9 and startDay = "Saturday", the output should be
// howManySundays(n, startDay) = 2;
// * For n = 7 and startDay = "Sunday", the output should be
// howManySundays(n, startDay) = 1.

int howManySundays(int n, std::string startDay) {

  std::vector<std::string> week = {"Monday", "Tuesday", "Wednesday",
      "Thursday", "Friday", "Saturday", "Sunday"};

  int startIndex = 0;

  for (int i = 0; i < week.size(); i++) {
    if (week[i] == startDay) {
      startIndex = i;
    }
  }

  return (n + startIndex) / week.size();
}
