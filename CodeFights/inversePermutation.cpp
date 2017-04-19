// Given a permutation, produce its inverse permutation.
// Example
// For permutation = [1, 3, 4, 2], the output should be
// inversePermutation(permutation) = [1, 4, 2, 3].

std::vector<int> inversePermutation(std::vector<int> permutation) {

  std::vector<int> result(permutation.size());

  for (int i = 0; i < permutation.size(); i++) {
    result[permutation[i] - 1] =  i+1 ;
  }

  return result;
}
