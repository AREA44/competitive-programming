// Check if the given point belongs to the given line.
// Example
// * For point = [0, 1] and line = [1, 1, 0], the output should be
// pointInLine(point, line) = false;
// * For point = [1, -1] and line = [1, 1, 0], the output should be
// pointInLine(point, line) = true.
// Check out the image below for better understanding: https://cloud.githubusercontent.com/assets/16760489/20436567/56a4d97a-ade3-11e6-846c-80c9046c2807.png

bool pointInLine(std::vector<int> point, std::vector<int> line) {
    return point[0] * line[0] + point[1] * line[1] + line[2] == 0;
}
