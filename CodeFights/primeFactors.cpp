// Write an algorithm that constructs an array of non unique prime factors of a number n.
// Example
// * For n = 100, the output should be
// primeFactors(n) = [2, 2, 5, 5].

std::vector<int> primeFactors(int n) {
  std::vector<int> factors;
  int divisor = 2;

  while (n >= 2) {
    if (n % divisor == 0) {
      n /= divisor;
      factors.push_back(divisor);
    }
    else {
      divisor++;
    }
  }
  return factors;
}
