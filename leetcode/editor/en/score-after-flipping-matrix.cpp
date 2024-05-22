#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int matrixScore(vector<vector<int>> &grid) {
    int base = 1;
    int res = 0;
    for (int column = grid[0].size() - 1; column > 0; --column) {
      int count0 = 0, count1 = 0;
      for (int row = 0; row < grid.size(); ++row) {
        (grid[row][0] == grid[row][column]) ? count1++ : count0++;
      }
      res += std::max(count0, count1) * base;
      base = base << 1;
    }
    res += base * grid.size();
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(score_after_flipping_matrix, demo) {
  Solution solution;
  vector<vector<int>> grid = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
  auto res = solution.matrixScore(grid);
  EXPECT_EQ(39, res);
}