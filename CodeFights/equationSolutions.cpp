// Given integers L and R, find the number of different pairs of integers A and B such that L <= A <= R and L <= B <= R and A3 = B2.
// Note that A and B may even coincide (A = B = 1 is one of the possibilities).
// Example
// * For L = 1 and R = 4, the output should be
// equationSolutions(L, R) = 1.
// There is only one solution: (1, 1).
// * For L = 1 and R = 8, the output should be
// equationSolutions(L, R) = 2.
// There are two solutions: (1, 1) and (4, 8)

int equationSolutions(int L, int R) {
    int result=0;
    for(int i=L;i<=R;i++)
        for(int j=L;j<=R;j++)
            if(i*i*i==j*j)
                result++;
    return result;
}
