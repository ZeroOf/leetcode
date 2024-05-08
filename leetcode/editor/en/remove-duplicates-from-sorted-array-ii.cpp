#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() < 3) {
      return nums.size();
    }
    int visited = 1;
    for (int i = 2; i < nums.size(); ++i) {
      if (nums[i] != nums[visited - 1]) {
        nums[++visited] = nums[i];
      }
    }
    return visited + 1;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(remove_duplicates_from_sorted_array_ii, demo) {
  Solution solution;
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  vector<int> expect = {1, 1, 2, 2, 3, 3};
  auto res = solution.removeDuplicates(nums);
  EXPECT_EQ(res, 5);
  EXPECT_EQ(nums, expect);
}