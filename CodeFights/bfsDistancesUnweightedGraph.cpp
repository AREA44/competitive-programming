// Given the adjacency matrix of the connected undirected graph with no loops or multiple edges and the index of the start vertex, find the distances between the start vertex and each vertex of the graph.
// Example
// For
// matrix = [[false, false, true],
//           [false, false, true],
//           [true, true, false]]
// and startVertex = 0, the output should be
// bfsDistancesUnweightedGraph(matrix, startVertex) = [0, 2, 1].
// Here's what the given graph looks like: https://cloud.githubusercontent.com/assets/16760489/20264429/1561c376-aa9e-11e6-8cc3-16f27b5028f2.png

std::vector<int> bfsDistancesUnweightedGraph(std::vector<std::vector<bool>> matrix, int startVertex) {

  bool visited[matrix.size()];
  std::fill_n(visited, matrix.size(), false);
  std::queue<int> q;
  std::vector<int> distance(matrix.size());
  visited[startVertex]=true;
  q.push(startVertex);
  while (q.size() != 0) {
    int currentVertex = q.front();
    q.pop();
    visited[currentVertex] = true;
    for (int nextVertex = 0; nextVertex < matrix.size(); ++nextVertex) {
      if (matrix[currentVertex][nextVertex] && !visited[nextVertex]) {
        visited[nextVertex] = true;
        distance[nextVertex] = distance[currentVertex] + 1;
        q.push(nextVertex);
      }
    }
  }

  return distance;
}
