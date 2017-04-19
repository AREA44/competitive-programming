// Given a set of points on the plane, find the area of its axis-aligned minimum bounding box.
// Example
// * For x = [1, 0, 4] and y = [-1, 2, 2], the output should be
// axisAlignedBoundingBox(x, y) = 12.
// In the image below points are given in blue, and the axis-aligned minimum bounding box is given in red. Its area is 3 * 4 = 12.
// https://cloud.githubusercontent.com/assets/16760489/20358509/97276b74-ac5e-11e6-88d1-6207b51435c0.png

int axisAlignedBoundingBox(std::vector<int> x, std::vector<int> y) {

  int minX = x[0],
      maxX = x[0],
      minY = y[0],
      maxY = y[0];

  for (int i = 1; i < x.size(); i++) {
    minX = std::min(x[i], minX);
    maxX = std::max(x[i], maxX);
    minY = std::min(y[i], minY);
    maxY = std::max(y[i], maxY);
  }

  return  (maxX-minX)*(maxY-minY) ;
}
