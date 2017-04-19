// Given an integer n consisting of an even number of digits, swap pairs of adjacent digits in it, i.e. swap the first digit with the second one, the third digit with the fourth one, etc.
// Example
// * For n = 1234, the output should be
// swapNeighbouringDigits(n) = 2143.

int swapNeighbouringDigits(int n) {

  int result = 0,
      tenPower = 1;
  while (n != 0) {
    int digit1 =  n % 10 ,
        digit2 = ((n - digit1) / 10) % 10;
    result += tenPower * (10 * digit1 + digit2);
    n /= 100;
    tenPower *= 100;
  }
  return result;
}
