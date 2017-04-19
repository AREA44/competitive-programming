// A semiprime is a positive integer number that is the product of two (not necessarily distinct) prime numbers.
// For a given n find the nth semiprime number.
// Example
// * For n = 1, the output should be
// semiprimeByNumber(n) = 4;
// * For n = 2, the output should be
// semiprimeByNumber(n) = 6.

int semiprimeByNumber(int n) {

  struct Helper {
    std::vector<int> generatePrimes(int n) {
      int current = 2;
      std::vector<int> primes;

      while (primes.size() < n) {
        bool isPrime = true;
        for (int i = 2; i * i <= current; i++) {
          if (current % i == 0) {
            isPrime = false;
            break;
          }
        }
        if (isPrime) {
          primes.push_back(current);
        }
        current++;
      }
      return primes;
    }
  };
  Helper h;

  std::vector<int> semiprimes;
  std::vector<int> primes = h.generatePrimes(n);

  for (int i = 0; i < primes.size(); i++) {
    for (int j = i; j < primes.size(); j++) {
      semiprimes.push_back(primes[i] * primes[j]);
    }
  }
  sort(semiprimes.begin(), semiprimes.end());

  return semiprimes[n - 1];
}
