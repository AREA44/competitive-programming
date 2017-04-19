// A continued fraction is a method of writing a rational fraction in the following format:https://cloud.githubusercontent.com/assets/16760489/20808957/23ee8e00-b837-11e6-963d-62df34b1d896.png
// You are given an array a containing values a1, a2, ..., an for some integer value n.
// Your task is to build a reduced fraction from it and return the product of its numerator and denominator.
// Example
// * For a = [2, 4], the output should be
// CFP(a) = 36.
// The fraction can be written as follows:https://cloud.githubusercontent.com/assets/16760489/20808969/2d0a26e8-b837-11e6-8e13-82e3b0218f65.png
// Thus, the output is 4 * 9 = 36.

int CFP(std::vector<int> a) {
    int i = a.size()-1,
         = 1,
        B = a[i];
    while(i >= 1){
        A += a[i-1] * B;
        swap(A, B);
        i--;
    }
    return A * B;
}
