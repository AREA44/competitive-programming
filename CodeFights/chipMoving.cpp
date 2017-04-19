// You are given a grid filled with non-negative integer numbers, and a chip is placed on the top left cell.
// On each turn the chip can be moved either to the right neighboring cell or to the bottom neighboring cell.
// The cost of the move is equal to the number written on the resulting cell.
// There is also an added cost if you change direction between two consecutive moves.
// In order to change the direction you'll need to pay an additional cost of 10.
// What is the minimum amount of points needed to reach the right bottom corner of the grid?
// Assume that you don't pay for standing on the upper left cell in the beginning, so the number on that cell is not used.
// It is guaranteed that each of all possible paths will cost less than 107 points.
// Example
// * For

// grid = [[ 0,  0, 99, 99, 99],
//         [99,  0,  0,  0, 99],
//         [99, 99, 99,  0, 99],
//         [99, 99, 99,  0, 99],
//         [99, 99, 99,  0,  0]]

// the output should be
// chipMoving(grid) = 40.
// You could avoid all the 99 spots but you would need to change direction 4 times.

int chipMoving(std::vector<std::vector<int>> grid) {

  const int MAX_COST = (int) 1e7;

  int n = grid.size(),
      m = grid[0].size();

  std::vector<std::vector<std::vector<int>>> dp(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::vector<int> tmp(2, MAX_COST);
      dp[i].push_back(tmp);
    }
  }

  dp[0][0][0] = 0;
  dp[0][0][1] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i < n - 1) {
        dp[i + 1][j][0] = std::min({dp[i + 1][j][0],
                                    dp[i][j][0] + grid[i + 1][j],
                                    dp[i][j][1] + grid[i + 1][j] + 10});
      }
      if (j < m - 1) {
        dp[i][j + 1][1] = std::min({dp[i][j + 1][1],
                                    dp[i][j][1] + grid[i][j + 1],
                                    dp[i][j][0] + grid[i][j + 1] + 10});
      }
    }
  }

  return std::min(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]);
}
