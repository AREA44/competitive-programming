// Given a sorted array of integers A, find such an integer x that ∑|A[i] - x| over all i has the minimum possible value.
// If there are several possible answers, output the smallest one.
// Example
// For [2, 4, 7], the output should be 4.

int absoluteValuesSumMinimization(std::vector<int> A) {
    sort(A.begin(),A.end());
    int result=1e9;
    int answer;
    for(int i=0;i<A.size();i++){
        int sum=0;
        for(int j=0;j<A.size();j++)
            sum+=abs(A[j]-A[i]);
        if(result>sum){
            result=sum;
            answer=A[i];
        }
    }
    return answer;
}
