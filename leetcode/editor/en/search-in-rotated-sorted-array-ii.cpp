#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool search(vector<int> &nums, int target) {
    int begin = 0, end = nums.size() - 1;
    while (begin <= end) {
      int mid = (begin + end) / 2;
      if (nums[mid] == target) {
        return true;
      }

      if (nums[mid] == nums[begin] && nums[mid] == nums[end]) {
        begin++;
        end--;
      } else if (nums[mid] >= nums[begin]) {
        if (target >= nums[begin] && target < nums[mid]) {
          end = mid - 1;
        } else {
          begin = mid + 1;
        }
      } else {
        if (target > nums[mid] && target <= nums[end]) {
          begin = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }
    return false;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(search_in_rotated_sorted_array_ii, demo) {
  Solution solution;

  vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
  auto ans = solution.search(nums, 0);
  EXPECT_EQ(ans, true);

  vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
  ans = solution.search(nums2, 3);
  EXPECT_EQ(ans, false);

  nums = {1, 0, 1, 1, 1};
  EXPECT_TRUE(solution.search(nums, 0));

  nums = {3, 1};
  EXPECT_TRUE(solution.search(nums, 1));
}