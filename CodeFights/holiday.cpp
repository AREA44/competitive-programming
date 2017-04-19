// John Doe likes holidays very much, and he was very happy to hear that his country's government decided to introduce yet another one.
// He heard that the new holiday will be celebrated each year on the xth week of month, on weekDay.
// Your task is to return the day of month on which the holiday will be celebrated in the year yearNumber.
// For your convenience, here are the lists of months names and lengths and the list of days of the week names.
// Months: "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December".
// Months lengths: 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31.
// Days of the week: "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday".
// Please, note that in leap years February has 29 days.
// Example

// * For x = 3, weekDay = "Wednesday", month = "November" and yearNumber = 2016, the output should be
// holiday(x, weekDay, month, yearNumber) = 16.
// The new holiday will be celebrated every November on the 3rd Wednesday of the month. In 2016 the 3rd Wednesday falls on the 16th of November.

// * For x = 5, weekDay = "Thursday", month = "November" and yearNumber = 2016, the output should be
// holiday(x, weekDay, month, yearNumber) = -1.
// There are only 4 Thursdays in November 2016.

int holiday(int x, std::string weekDay, std::string month, int yearNumber) {
  const std::vector<std::string> months{
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
  };
  const std::vector<std::string> daysInWeek{
    "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday", "Sunday"
  };
  const std::vector<int> days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  struct Helper {
    bool isLeap(int year) {
      return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    }

    int countLeap(int yearLeft, int yearRight) {
      int result = 0;
      for (int i = yearLeft; i <= yearRight; i++) {
        if (isLeap(i)) {
          result++;
        }
      }
      return result;
    }

    int getDaysInMonth(const std::vector<int> &days, int month, int year) {
      int result = days[month];
      if (isLeap(year) && month == 1) {
        result++;
      }
      return result;
    }
  };

  int weekDayInt = std::find(daysInWeek.begin(),
                             daysInWeek.end(),
                             weekDay) - daysInWeek.begin();
  int monthInt = std::find(months.begin(),
                           months.end(),
                           month) - months.begin();

  /* 01 January 2015 is Thursday */
  Helper h;
  int leaps = h.countLeap(2015, yearNumber - 1) ;
  int thursdayIndex = std::find(daysInWeek.begin(),
                                daysInWeek.end(),
                                "Thursday") - daysInWeek.begin();
  int newWeekDay = (thursdayIndex + leaps * 366 +
                    (yearNumber - 2015 - leaps) * 365) % 7;
  for (int i = 0; i < monthInt; i++) {
    newWeekDay = (newWeekDay + h.getDaysInMonth(days, i, yearNumber)) % 7;
  }
  int daysCount = 0;
  int daysInMonth = h.getDaysInMonth(days, monthInt, yearNumber);
  for (int i = 1; i <= daysInMonth; i++) {
    if (newWeekDay == weekDayInt) {
      daysCount++;
    }
    if (daysCount == x) {
      return i;
    }
    newWeekDay = (newWeekDay + 1) % 7;
  }
  return -1;
}
