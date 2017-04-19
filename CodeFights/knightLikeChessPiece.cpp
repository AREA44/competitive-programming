// Define as (a, b) knight-like chess piece (where 0 < a ≤ b) the piece that changes one of its coordinates by a and the other one by b on each move (so (1, 2) knight-like chess piece is the usual chess knight). We need to find the number of different (a, b) knight-like chess pieces that can reach the bottom right corner of n by m chess board starting from the top left corner.
// Note that a and b don't have to be different from each other.
// Example
// * For n = 3 and m = 3, the output should be
// knightLikeChessPiece(n, m) = 3.
// Here are all three valid knight-like chess pieces:https://cloud.githubusercontent.com/assets/16760489/20435664/7ed96b44-addf-11e6-824e-7ffe259bbc4c.png

typedef std::vector<std::vector<bool>> booleanArray2D;

int knightLikeChessPiece(int n, int m) {

  struct Helper {
    void dfs(int x, int y, int a, int b,
             int n, int m, booleanArray2D & visited) {
      if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
        visited[x][y] = true;
        dfs(x + a, y + b, a, b, n, m, visited);
        dfs(x + b, y + a, a, b, n, m, visited);
        dfs(x - a, y + b, a, b, n, m, visited);
        dfs(x - b, y + a, a, b, n, m, visited);
        dfs(x - a, y - b, a, b, n, m, visited);
        dfs(x - b, y - a, a, b, n, m, visited);
        dfs(x + a, y - b, a, b, n, m, visited);
        dfs(x + b, y - a, a, b, n, m, visited);
      }
    }
  };

  Helper h;

  int result = 0;
  for (int a = 1; a < std::min(n, m); a++) {
    for (int b = a; b < std::max(n, m); b++) {
      std::vector<bool> line(m, false);
      booleanArray2D visited(n, line);
      h.dfs(0, 0, a, b, n, m, visited);
      if (visited[n - 1][m - 1]) {
        result++;
      }
    }
  }
  return result;
}
