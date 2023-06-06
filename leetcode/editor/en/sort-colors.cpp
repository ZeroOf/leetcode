//Given an array nums with n objects colored red, white, or blue, sort them in-
//place so that objects of the same color are adjacent, with the colors in the 
//order red, white, and blue. 
//
// We will use the integers 0, 1, and 2 to represent the color red, white, and 
//blue, respectively. 
//
// You must solve this problem without using the library's sort function. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]
// 
//
// Example 2: 
//
// 
//Input: nums = [2,0,1]
//Output: [0,1,2]
// 
//
// 
// Constraints: 
//
// 
// n == nums.length 
// 1 <= n <= 300 
// nums[i] is either 0, 1, or 2. 
// 
//
// 
// Follow up: Could you come up with a one-pass algorithm using only constant 
//extra space? 
//
// Related Topics Array Two Pointers Sorting 👍 11892 👎 446

#include <all.h>
namespace sort_colors {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  void sortColors(vector<int> &nums) {
    int cur = 0, afterRed = 0, beforeBlue = nums.size() - 1;
    while(cur <= beforeBlue) {
      if (nums[cur] == 0) {
        swap(nums[afterRed], nums[cur]);
        ++cur;
        ++afterRed;
      } else if (nums[cur] == 1) {
        ++cur;
      } else {
        swap(nums[cur], nums[beforeBlue]);
        --beforeBlue;
      }
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}