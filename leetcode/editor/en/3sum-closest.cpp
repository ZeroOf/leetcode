//Given an integer array nums of length n and an integer target, find three 
//integers in nums such that the sum is closest to target. 
//
// Return the sum of the three integers. 
//
// You may assume that each input would have exactly one solution. 
//
// 
// Example 1: 
//
// 
//Input: nums = [-1,2,1,-4], target = 1
//Output: 2
//Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// 
//
// Example 2: 
//
// 
//Input: nums = [0,0,0], target = 1
//Output: 0
//Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
// 
//
// 
// Constraints: 
//
// 
// 3 <= nums.length <= 1000 
// -1000 <= nums[i] <= 1000 
// -10⁴ <= target <= 10⁴ 
// 
//
// Related Topics Array Two Pointers Sorting 👍 7664 👎 416

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