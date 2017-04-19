// You are given a string S (|S| ≤ 12) consisting of English lowercase letters. Compute the number of different anagrams of S.
// Example
// For S = "ab", the output should be
// numberOfAnagrams(S) = 2.
// String "ab" has two anagrams: "ab" and "ba".

int factorial(int n){
    int prod = 1;
    for (int i = 2; i <= n; i++) {
      prod *= i;
    }
    return prod;
}

int numberOfAnagrams(std::string S) {
  int charCount[26];
  for(int i=0;i<26;i++) charCount[i]=0;

  for (int i = 0; i < S.size(); i++) {
    charCount[S[i]-'a']++;
  }

  int answer = factorial(S.size());
    
  for (int i=0;i<26;i++) {
    answer/=factorial(charCount[i]);
  }

  return answer;
}
