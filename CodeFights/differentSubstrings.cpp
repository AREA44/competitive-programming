// Given a string, find the number of different non-empty substrings in it.
// Example
// For inputString = "abac", the output should be
// differentSubstrings(inputString) = 9.

string substring(std::string inputString, int start, int end){
    std::string resultString;
    for(int i=start;i<end;i++)
        resultString+=inputString[i];
    return resultString;
}

int differentSubstrings(std::string inputString) {
    std::vector<std::string> substrings;
    int result = 1;
    for (int i = 0; i < inputString.size(); i++) {
        for (int j = i + 1; j <= inputString.size(); j++) {
            substrings.push_back(substring(inputString,i,j));
        }
    }
    sort(substrings.begin(),substrings.end());
    for (int i = 1; i < substrings.size(); i++) {
        if (substrings[i] != substrings[i - 1]) {
            result++;
        }
    }
    return result;
}
