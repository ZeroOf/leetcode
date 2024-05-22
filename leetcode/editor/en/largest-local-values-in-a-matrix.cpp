#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
    vector<vector<int>> res(grid.size() - 2, vector<int>(grid.size() - 2, 0));

    for (int i = 0; i < res.size(); ++i) {
      for (int j = 0; j < res[0].size(); ++j) {
        res[i][j] = std::max({grid[i][j], grid[i][j + 1], grid[i][j + 2],
                              grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2],
                              grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2],
                             });
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(largest_local_values_in_a_matrix, demo) {
  Solution solution;
  vector<vector<int>> grid = {
      {9, 9, 8, 1},
      {5, 6, 2, 6},
      {8, 2, 6, 4},
      {6, 2, 2, 2}
  };
  auto res = solution.largestLocal(grid);
  vector<vector<int>> expect = {
      {9, 9},
      {8, 6}
  };
  EXPECT_EQ(res, expect);
}