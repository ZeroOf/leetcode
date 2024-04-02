#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:

// 1. find the longest subarray and write down the index of maxK and minK
  // 2. sum the subarray count for every valid start index(count of numbers after the nearest )
  long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    long long ans = 0;
    int maxi = -1, mini = -1;
    int s = nums.size();
    for (int r = 0, l = 0; r < s; r++) {
      int x = nums[r];
      if (x < minK || x > maxK) {// x exceeds the bound
        l = r + 1; // move l to r+1
        continue;
      }
      if (x == maxK) maxi = r; // position for maxK
      if (x == minK) mini = r; // position for minK
      ans += max((min(maxi, mini) - l + 1), 0);
    }
    return ans;
  }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(count_subarrays_with_fixed_bounds, demo) {
  Solution solution;

  vector<int> input{1, 3, 5, 2, 7, 5};
  EXPECT_EQ(solution.countSubarrays(input, 1, 5), 2);
  input = {1, 1, 1, 1};
  EXPECT_EQ(solution.countSubarrays(input, 1, 1), 10);
}