#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  // 1. go to the furthest index use bricks, and use max heap to store the filled bricks;
  // 2. replace the max bricks with ladder when bricks not enough
  // 3. when no ladder and brick cannot fill, return
  int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    priority_queue<int> filledBricks;
    auto i = 0;

    // 1. go to the furthest index use bricks, and use max heap to store the filled bricks;
    for(; i < heights.size()-1; ++i) {
      auto diff = heights[i+1] - heights[i];
      if (diff > bricks) {
        break;
      }
      bricks -= diff;
      filledBricks.push(diff);
    }

  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(furthest_building_you_can_reach, demo) {
  Solution solution;
}