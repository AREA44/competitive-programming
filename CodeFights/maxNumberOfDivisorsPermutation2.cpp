// Given an integer, rearrange its digits in such a way that the resulting value will have the maximal possible number of divisors.
// If there are several possible solutions, return the largest one.
// Example
// * For n = 21, the output should be
// maxNumberOfDivisorsPermutation2(n) = 12.
// 12 has 6 divisors, while 21 has only 4 divisors.

// * For n = 111, the output should be
// maxNumberOfDivisorsPermutation2(n) = 111.

int maxNumberOfDivisorsPermutation2(int n) {

  struct Helper {
    int digits[10];
    int bestNumber;
    int maxDivisors;

    Helper() {
      for (int i = 0; i < 10; i++) {
        digits[i] = 0;
      }
      bestNumber = -1;
      maxDivisors = 0;
    }

    void generatePermutation(int curValue) {
      bool lastStep = true;
      for (int i = 9; i >= 0; i--) {
        if (digits[i] > 0) {
          digits[i]--;
          generatePermutation(curValue * 10 + i);
          digits[i]++;        
          lastStep = false;
        }
      }
      if (lastStep) {
        int cntDivisors = 0;
        for (int i = 1; i <= curValue; i++) {      
          if (curValue % i == 0) {
            cntDivisors++;
          }
        }
        if (cntDivisors > maxDivisors) {
          bestNumber = curValue;
          maxDivisors = cntDivisors;
        }
      }    
    }    
  };

  Helper h;

  while (n > 0) {
    h.digits[n % 10]++;
    n /= 10;
  }

  h.generatePermutation(0);

  return h.bestNumber;
}
