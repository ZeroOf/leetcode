#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<string> findRelativeRanks(vector<int> &score) {
    auto compare = [&score](int lhs, int rhs) {
      return score[lhs] < score[rhs];
    };
    std::priority_queue<int, std::vector<int>, decltype(compare)> sorter(compare);

    for (int i = 0; i < score.size(); ++i) {
      sorter.push(i);
    }
    vector<string> res(score.size());
    do {
      // first
      res[sorter.top()] = "Gold Medal";
      sorter.pop();
      //second
      if (sorter.empty()) {
        break;
      }
      res[sorter.top()] = "Silver Medal";
      sorter.pop();
      // third
      if (sorter.empty()) {
        break;
      }
      // remain
      res[sorter.top()] = "Bronze Medal";
      sorter.pop();
      for (int i = 4; !sorter.empty(); i++) {
        res[sorter.top()] = to_string(i);
        sorter.pop();
      }
    } while (0);
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(relative_ranks, demo) {
  Solution solution;
  vector<int> score = {10, 3, 8, 9, 4};
  auto res = solution.findRelativeRanks(score);
  vector<string> expect = {"Gold Medal", "5", "Bronze Medal", "Silver Medal", "4"};
  ASSERT_EQ(res, expect);
}