#include <all.h>
#include <numeric>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int tribonacci(int n) {
    if (n < tribonacci_.size()) {
      return tribonacci_[n];
    }
    for (int i = tribonacci_.size(); i <= n; ++i) {
      tribonacci_.push_back(std::accumulate(tribonacci_.end() - 3, tribonacci_.end(), 0));
    }
    return tribonacci_[n];
  }

 private:
  static vector<int> tribonacci_;
};

vector<int> Solution::tribonacci_{0, 1, 1};
//leetcode submit region end(Prohibit modification and deletion)


TEST(n_th_tribonacci_number, demo) {
  Solution solution;
  EXPECT_EQ(solution.tribonacci(3), 2);
  EXPECT_EQ(solution.tribonacci(4), 4);
  EXPECT_EQ(solution.tribonacci(5), 7);
  EXPECT_EQ(solution.tribonacci(6), 13);
}