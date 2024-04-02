#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int firstMissingPositive(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      // nums[i] should be in nums[nums[i] - 1], if nums[nums[i] - 1] not nums[i], put the nums[i] in the right pos
      // if equal, go to next, break forever loop
      if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      } else {
        ++i;
      }
    }
    i = 0;
    while (i < nums.size()) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
      i++;
    }
    return nums.size() + 1;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(first_missing_positive, demo) {
  Solution solution;

  vector<int> input{1, 2, 0};
  EXPECT_EQ(solution.firstMissingPositive(input), 3);

  input = {3, 4, -1, 1};
  EXPECT_EQ(solution.firstMissingPositive(input), 2);

  input = {7, 8, 9, 11, 12};
  EXPECT_EQ(solution.firstMissingPositive(input), 1);
}