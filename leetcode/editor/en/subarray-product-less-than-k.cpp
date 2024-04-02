#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k <= 1) {
      return 0;
    }
    int count = 0;
    // [start,end)
    size_t start = 0;
    size_t end = 0;
    int product = 1;
    for (int left = 0, right = 0; right < nums.size(); right++) {
      product *= nums[right];

      // when nums[right] >- product, left = right+1
      while (product >= k) {
        product /= nums[left++];
      }

      // count [left,right]
      count += right - left + 1;
    }

    return count;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(subarray_product_less_than_k, demo) {
  Solution solution;
  vector<int> input{10, 5, 2, 6};
  EXPECT_EQ(solution.numSubarrayProductLessThanK(input, 100), 8);

  input = {1, 2, 3};
  EXPECT_EQ(solution.numSubarrayProductLessThanK(input, 0), 0);
}