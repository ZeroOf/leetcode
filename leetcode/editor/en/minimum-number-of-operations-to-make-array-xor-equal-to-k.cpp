#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int minOperations(vector<int> &nums, int k) {
    int xorRes = 0;
    for (auto &num : nums) {
      xorRes ^= num;
    }
    xorRes ^= k;
    return __builtin_popcount(xorRes);
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(minimum_number_of_operations_to_make_array_xor_equal_to_k, demo) {
  Solution solution;
  std::vector<int> input{2, 1, 3, 4};
  EXPECT_EQ(solution.minOperations(input, 1), 2);
  input = {2, 0, 2, 0};
  EXPECT_EQ(solution.minOperations(input, 0), 0);
}