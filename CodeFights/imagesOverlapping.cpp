// A monochrome image may be represented by a 2-dimensional array of booleans for each cell of which true means that the corresponding pixel of the image is black, while false means it's white. Given two images, find the number of the ways to place the second image over the first one in such a way that each pixel of the second image is above some pixel of the first one and no pair of black pixels are placed above each other.
// Example
// For
// largeImg = [[false, true, false],
//             [true, false, true]]
// and
// smallImg = [[true, false]]
// the output should be
// imagesOverlapping(largeImg, smallImg) = 2.
// Check out the image below for better understanding: https://cloud.githubusercontent.com/assets/16760489/20213253/43f8c376-a83a-11e6-951d-ff1633d5c6d8.png

typedef std::vector<std::vector<bool>> matrix;

int imagesOverlapping(matrix largeImg, matrix smallImg) {

  int result = 0;

  for (int i = 0; i + smallImg.size() <= largeImg.size(); i++) {
    for (int j = 0;  j + smallImg[0].size() <= largeImg[0].size() ; j++) {
      bool correct = true;
      for (int k = 0; k < smallImg.size(); k++) {
        for (int t = 0; t < smallImg[0].size(); t++) {
          if (smallImg[k][t] && largeImg[i + k][j + t]) {
            correct = false;
          }
        }
      }
      if (correct) {
        result++;
      }
    }
  }

  return result;
}
