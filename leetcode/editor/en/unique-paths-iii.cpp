//You are given an m x n integer array grid where grid[i][j] could be: 
//
// 
// 1 representing the starting square. There is exactly one starting square. 
// 2 representing the ending square. There is exactly one ending square. 
// 0 representing empty squares we can walk over. 
// -1 representing obstacles that we cannot walk over. 
// 
//
// Return the number of 4-directional walks from the starting square to the 
//ending square, that walk over every non-obstacle square exactly once. 
//
// 
// Example 1: 
// 
// 
//Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
//Output: 2
//Explanation: We have the following two paths: 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
//2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
// 
//
// Example 2: 
// 
// 
//Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
//Output: 4
//Explanation: We have the following four paths: 
//1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
//2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
//3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
//4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
// 
//
// Example 3: 
// 
// 
//Input: grid = [[0,1],[2,0]]
//Output: 0
//Explanation: There is no path that walks over every empty square exactly once.
//
//Note that the starting and ending square can be anywhere in the grid.
// 
//
// 
// Constraints: 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 20 
// 1 <= m * n <= 20 
// -1 <= grid[i][j] <= 2 
// There is exactly one starting cell and one ending cell. 
// 
//
// Related Topics Array Backtracking Bit Manipulation Matrix 👍 3887 👎 155

#include <all.h>
namespace unique_paths_iii {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool stepAll(vector<vector<int>> grid, int x, int y) {
    for (const auto &line : grid) {
      for (const auto oneGrid : line) {
        if (oneGrid == 0) {
          return false;
        }
      }
    }
    if (x > 0 && grid[x - 1][y] == 2 || x < grid.size() - 1 && grid[x + 1][y] == 2 || y > 0 && grid[x][y - 1] == 2
        || y < grid[0].size() - 1 && grid[x][y + 1] == 2) {
      return true;
    }
    return false;
  }
  void uniquePathsIII(vector<vector<int>> grid, int x, int y, int &result) {
    if (hasPath(grid, x, y)) {
      grid[x][y] = -1;
      if (x > 0 && grid[x - 1][y] == 0) {
        grid[x - 1][y] = 1;
        uniquePathsIII(grid, x - 1, y, result);
        grid[x - 1][y] = 0;
      }
      if (x < grid.size() - 1 && grid[x + 1][y] == 0) {
        grid[x + 1][y] = 1;
        uniquePathsIII(grid, x + 1, y, result);
        grid[x + 1][y] = 0;
      }
      if (y > 0 && grid[x][y - 1] == 0) {
        grid[x][y - 1] = 1;
        uniquePathsIII(grid, x, y - 1, result);
        grid[x][y - 1] = 0;
      }
      if (y < grid[0].size() - 1 && grid[x][y + 1] == 0) {
        grid[x][y + 1] = 1;
        uniquePathsIII(grid, x, y + 1, result);
        grid[x][y + 1] = 0;
      }
    } else if (stepAll(grid, x, y)) {
      ++result;
    }
  }
  int uniquePathsIII(vector<vector<int>> &grid) {
    auto start = findStart(grid);
    int x = start.first, y = start.second;
    int result = 0;
    uniquePathsIII(grid, x, y, result);
    return result;
  }
  bool hasPath(vector<vector<int>> &grid, int x, int y) {
    if (x > 0 && grid[x - 1][y] == 0) {
      return true;
    }
    if (x < grid.size() - 1 && grid[x + 1][y] == 0) {
      return true;
    }
    if (y > 0 && grid[x][y - 1] == 0) {
      return true;
    }
    if (y < grid[0].size() - 1 && grid[x][y + 1] == 0) {
      return true;
    }
    return false;
  }
  pair<int, int> findStart(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          return pair<int, int>(i, j);
        }
      }
    }
    return pair<int, int>();
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}