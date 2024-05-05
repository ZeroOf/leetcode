#include <all.h>

namespace three_sum_closest {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int threeSumClosest(vector<int> &nums, int target) {
    if (nums.size() < 3) {
      return 0;
    }
    std::sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2];
    for (int first = 0; first < nums.size() - 2; ++first) {
      // after start from first of a group of same numbers, has travel all possible combination of it,
      // so next time, we start from the next different number
      if (first > 0 && nums[first] == nums[first - 1]) {
        continue;
      }
      int second = first + 1, third = nums.size() - 1;
      while (second < third) {
        int sum = nums[first] + nums[second] + nums[third];
        if (sum == target) {
          return sum;
        }
        if (abs(target - sum) < abs(target - closest)) {
          closest = sum;
        }
        if (sum > target) {
          --third;
        } else {
          ++second;
        }
      }
    }
    return closest;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}

TEST(threeSumClosest, demo) {
  three_sum_closest::Solution s;
  vector<int> nums = {-1, 2, 1, -4};
  EXPECT_EQ(s.threeSumClosest(nums, 1), 2);

  nums = {0, 0, 0};
  EXPECT_EQ(s.threeSumClosest(nums, 1), 0);

  nums = {1, 1, 1};
  EXPECT_EQ(s.threeSumClosest(nums, 2), 3);
}