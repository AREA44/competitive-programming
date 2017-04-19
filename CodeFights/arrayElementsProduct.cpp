// Given an array of integers, find the product of its elements.
// Example
// * For inputArray = [1, 3, 2, 10], the output should be
// arrayElementsProduct(inputArray) = 60.

int arrayElementsProduct(std::vector<int> inputArray) {
    int result=1;
    for(int i=0;i<inputArray.size();i++){
        result*=inputArray[i];
    }
    return result;
}
