// Consider several points lying on a straight line.
// Call an unordered triple of points an equidistant triple if one of them is the mid-point of the segment formed by the other two.
// Given the coordinates of the points, find the number of equidistant triples formed by them.
// Example
// * For coordinates = [1, 2, 4, 6, 7, 8], the output should be
// equidistantTriples(coordinates) = 4.
// The equidistant triples are: (1, 4, 7), (2, 4, 6), (4, 6, 8), (6, 7, 8).
// Check out the image below for better understanding: https://cloud.githubusercontent.com/assets/16760489/20828407/08cf8cbe-b8aa-11e6-9ec0-1f0c000203d5.png

int equidistantTriples(std::vector<int> coordinates) {

  int ans = 0;
  for (int i = 1; i < (int)coordinates.size() - 1; i++) {
    int left = i - 1;
    int right = i + 1;
    while (left >= 0 && right < coordinates.size()) {
      int distL = coordinates[i] - coordinates[left] ;
      int distR = coordinates[right] - coordinates[i];
      if (distL == distR) {
        ans++;
        left--;
        right++;
      } else if (distL < distR) {
        left--;
      } else {
        right++;
      }
    }
  }

  return ans;
}
