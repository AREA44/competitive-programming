// Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with digits so that each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid contains all of the digits from 1 to 9.
// This algorithm should check if the given grid of numbers represents a correct solution to Sudoku.
// Example
// * For the first example below, the output should be true. For the other grid, the output should be false: each of the nine 3 × 3 sub-grids should contain all of the digits from 1 to 9.
// https://cloud.githubusercontent.com/assets/16760489/20314303/5cdac31c-ab8c-11e6-8d2d-b658bb5bab6f.png

bool sudoku(std::vector<std::vector<int>> grid) {

  struct Helper {
    bool checkBlock(std::vector<int> block) {
      std::vector<int> sample;
      for (int i = 1; i < 10; i++) {
        sample.push_back(i);
      }
      std::sort(block.begin(), block.end());
      if (block == sample) {
        return true;
      }
      return false;
    }
  };
  Helper h;

  std::vector<std::vector<std::vector<int>>> subgrids;

  for (int i = 0; i < 3; i++) {
    std::vector<std::vector<int>> tmp;
    subgrids.push_back(tmp);
    for (int j = 0; j < 3; j++) {
      std::vector<int> tmp;
      subgrids[i].push_back(tmp);
    }
  }

  for (int i = 0; i < 9; i++) {
    std::vector<int> horizontal, vertical;
    for (int j = 0; j < 9; j++) {
      horizontal.push_back(grid[i][j]);
      vertical.push_back(grid[j][i]);
      subgrids[i / 3][j / 3].push_back(grid[i][j]);
    }
    if (!h.checkBlock(horizontal)) {
      return false;
    }
    if (!h.checkBlock(vertical)) {
      return false;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (!h.checkBlock(subgrids[i][j])) {
        return false;
      }
    }
  }

  return true;
}
