// Given the adjacency matrix of an undirected graph with no loops or multiple edges, find the size of the connected component of vertex 1 (0-based).
// Example
// * For
// matrix = [[false, true, false],
//           [true, false, false],
//           [false, false, false]]
// the output should be
// bfsComponentSize(matrix) = 2.
// The component contains vertices 0 and 1.
// https://cloud.githubusercontent.com/assets/16760489/20565167/f84d571a-b1c2-11e6-91b3-865fbbc56c89.png

// * For
// matrix = [[false, false, true, false],
//           [false, false, false, false],
//           [true, false, false, true],
//           [false, false, true, false]]
// the output should be
// bfsComponentSize(matrix) = 1.
// The component consists of a single vertex 1.
// https://cloud.githubusercontent.com/assets/16760489/20565189/14e6f2d2-b1c3-11e6-8047-951d1b96269e.png

int bfsComponentSize(std::vector<std::vector<bool>> matrix) {
    vector<int> visited;
    queue<int> queue;
    int componentSize = 0;
    for (int i = 0; i < matrix.size(); i++) {
      visited.push_back(false);
    }
    visited[1] = true;
    queue.push(1);
    while (queue.size()) {
    int currentVertex = queue.front();
        queue.pop();
        visited[currentVertex] = true;
        componentSize++;
        for (int nextVertex = 0; nextVertex < matrix.size(); nextVertex++) {
          if (matrix[currentVertex][nextVertex] && !visited[nextVertex]) {
            visited[nextVertex] = true;
            queue.push(nextVertex);
          }
        }
    }
    return componentSize;
}
