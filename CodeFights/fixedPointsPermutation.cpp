// Find the number of fixed points in a permutation of [1, 2, 3, ..., n] for some n.
// Example
// For permutation = [1, 3, 2, 4, 5, 6], the output should be
// fixedPointsPermutation(permutation) = 4.
// The answer is 4 since 1, 4, 5 and 6 stayed in the same positions.

int fixedPointsPermutation(std::vector<int> permutation) {
    int answer=0;
    for(int i=0;i<permutation.size();i++)
        if(permutation[i]==i+1)
            answer++;
    return answer;
}
