#include <all.h>
namespace check_if_it_is_a_straight_line {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    // math problem, y = ax + b
    // y1 = ax1 + b
    // y2 = ax2 + b
    // y3 = ax3 + b
    // y3 - y1 = a(x3 - x1)
    // y3 - y2 = a(x3 - x2)
    // (x3-x2) * (y3 - y1) = (x3 - x1) * (y3 - y2)
    for (int i = 2; i < coordinates.size(); ++i) {
      if ((coordinates[i][0] - coordinates[0][0]) * (coordinates[i][1] - coordinates[1][1])
          != (coordinates[i][0] - coordinates[1][0]) * (coordinates[i][1] - coordinates[0][1])) {
        return false;
      }
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}

TEST(check_if_it_is_a_straight_line, demo) {
  check_if_it_is_a_straight_line::Solution solution;
  vector<vector<int>> input{
      {1, 2},
      {2, 3},
      {3, 4},
      {4, 5},
      {5, 6}
  };
  EXPECT_TRUE(solution.checkStraightLine(input));
}