#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  long long maximumHappinessSum(vector<int> &happiness, int k) {
    std::sort(happiness.begin(), happiness.end());
    long long res = 0;
    for (int i = 0; i < k; ++i) {
      auto curr = *(happiness.end() - i - 1) - i;
      if (curr <= 0) {
        break;
      }
      res += curr;
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(maximize_happiness_of_selected_children, demo) {
  Solution solution;
  vector<int> happiness = {1, 2, 3};
  EXPECT_EQ(solution.maximumHappinessSum(happiness, 2), 4);

  happiness = {2, 3, 4, 5};
  EXPECT_EQ(solution.maximumHappinessSum(happiness, 1), 5);

  happiness = {1, 1, 1, 1};
  EXPECT_EQ(solution.maximumHappinessSum(happiness, 2), 1);
}