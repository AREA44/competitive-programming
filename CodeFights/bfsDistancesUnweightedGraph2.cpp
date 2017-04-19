// Given the adjacency matrix of the connected undirected graph with no loops or multiple edges, find the distance between the two specified vertices.
// Example
// * For
// matrix = [[false, false, true],
//           [false, false, true],
//           [true, true, false]]
// vertex1 = 0 and vertex2 = 1, the output should be
// bfsDistancesUnweightedGraph2(matrix, vertex1, vertex2) = 2.
// Here's what the given graph looks like:https://cloud.githubusercontent.com/assets/16760489/20313051/3b03d6e2-ab88-11e6-989b-e0dfaa826d9d.png

int bfsDistancesUnweightedGraph2(std::vector<std::vector<bool>> matrix, int vertex1, int vertex2) {

  bool visited[matrix.size()];
  std::fill_n(visited, matrix.size(), false);
  std::queue<int> q;
  std::vector<int> distance(matrix.size());

  visited[vertex1] = true;
  q.push(vertex1);
  while (q.size() > 0) {
    int currentVertex = q.front();
    q.pop();
    visited[currentVertex] = true;
    for (int nextVertex = 0; nextVertex < matrix.size(); ++nextVertex) {
      if (matrix[currentVertex][nextVertex] && !visited[nextVertex]) {
        visited[nextVertex] = true;
        distance[nextVertex] =  distance[currentVertex] + 1 ;
        q.push(nextVertex);
      }
    }
  }

  return distance[vertex2];
}
