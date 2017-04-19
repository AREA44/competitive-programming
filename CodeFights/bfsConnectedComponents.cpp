// Given the adjacency matrix of an undirected graph with no loops or multiple edges, find the number of connected components in the given graph.
// Example
// * For
// matrix = [[false, true, false],
//           [true, false, false],
//           [false, false, false]]
// the output should be
// bfsConnectedComponents(matrix) = 2.
// Here's how the given graph looks like: https://cloud.githubusercontent.com/assets/16760489/20538595/7c663502-b124-11e6-9259-595642fb1fa1.png

int bfsConnectedComponents(std::vector<std::vector<bool>> matrix) {
    vector<int> visited;
    queue<int> queue;
    int componentsCount = 0;
    for (int i = 0; i < matrix.size(); i++) {
      visited.push_back(false);
    }
    for (int startVertex = 0; startVertex < matrix.size(); startVertex++) {
      if (!visited[startVertex]) {
        componentsCount++;
        visited[startVertex] = true;
        queue.push(startVertex);
        while (queue.size()) {
          int currentVertex = queue.front();
            queue.pop();
          visited[currentVertex] = true;
          for (int nextVertex = 0; nextVertex < matrix.size();nextVertex++) {
            if (matrix[currentVertex][nextVertex] && !visited[nextVertex]) {
              visited[nextVertex] = true;
              queue.push(nextVertex);
            }
          }
        }
      }
    }
    return componentsCount;
}
