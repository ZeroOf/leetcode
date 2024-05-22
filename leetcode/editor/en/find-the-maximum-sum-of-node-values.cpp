#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges) {
    vector<vector<long long>> memo(nums.size(), vector<long long>(2, -1));
    return maxSumOfNodes(0, 1, nums, k, memo);
  }

 private:
  long long maxSumOfNodes(int index, int isEven, vector<int> &nums, int k, vector<vector<long long>> &memo) {
    if (index == nums.size()) {
      return isEven == 1 ? 0 : INT_MIN;
    }

    if (memo[index][isEven] != -1) {
      return memo[index][isEven];
    }

    long long noXorDone = nums[index] + maxSumOfNodes(index + 1, isEven, nums, k, memo);
    long long xorDone = (nums[index] ^ k) + maxSumOfNodes(index + 1, isEven ^ 1, nums, k, memo);

    return memo[index][isEven] = max(xorDone, noXorDone);
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(find_the_maximum_sum_of_node_values, demo) {
  Solution solution;
  vector<int> input = {1, 2, 1};
  vector<vector<int>> edges = {{0, 1}, {0, 2}};

  ASSERT_EQ(solution.maximumValueSum(input, 3, edges), 6);

  input = {1, 4, 3, 2};
  edges = {{0, 1}, {1, 2}, {1, 3}};
  ASSERT_EQ(solution.maximumValueSum(input, 5, edges), 18);

  input = {7, 7, 7, 7, 7, 7};
  edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}};
  ASSERT_EQ(solution.maximumValueSum(input, 3, edges), 42);
}