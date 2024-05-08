#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    subsets(0, std::vector<int>{}, nums, res);
    return res;
  }

 private:
  void subsets(int startIndex, vector<int> visited, const vector<int> &nums, vector<vector<int>> &res) {
    if (startIndex == nums.size()) {
      res.push_back(visited);
      return;
    }
    // skip visit startIndex
    subsets(startIndex + 1, visited, nums, res);

    // visit startIndex
    visited.push_back(nums[startIndex]);
    subsets(startIndex + 1, visited, nums, res);
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(subsets, demo) {
  Solution solution;

  std::vector<int> input{1, 2, 3};
  auto res = solution.subsets(input);
  std::sort(res.begin(), res.end());
  std::vector<std::vector<int>> expect{{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}};
  std::sort(expect.begin(), expect.end());
  EXPECT_EQ(res, expect);


  input = std::vector<int>{0};
  res = solution.subsets(input);
  std::sort(res.begin(), res.end());
  expect = std::vector<std::vector<int>>{{}, {0}};
  EXPECT_EQ(res, expect);
}