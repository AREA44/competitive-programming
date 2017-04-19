// Implement a function that can subtract two reduced fractions and produce a new one.
// Example
// * For A = [7, 10] and B = [3, 10], the output should be
// fractionSubtraction(A, B) = [2, 5].
// 7/10 - 3/10 = 4/10 = 2/5, so the answer is [2, 5].

std::vector<int> fractionSubtraction(std::vector<int> A, std::vector<int> B) {

  struct Helper {
    int gcdEuclid(int a, int b) {
      if (a == 0) {
        return b;
      }
      return gcdEuclid(b % a, a);
    }
  };
  Helper h;

  std::vector<int> C(2);
  C[0] = A[0] * B[1] - A[1] * B[0], C[1] = A[1] * B[1];
  int gcd =  h.gcdEuclid(C[0], C[1]) ;

  C[0] /= gcd;
  C[1] /= gcd;

  return C;
}
