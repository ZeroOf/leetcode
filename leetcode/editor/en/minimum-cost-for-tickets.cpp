#include <all.h>
namespace minimum_cost_for_tickets {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    vector<int> dp(days.back() + 1, 0);
    std::set<int> dayset(days.begin(), days.end());
    for (int i = 1; i < dp.size(); i++) {
      if (dayset.find(i) == dayset.end()) {
        dp[i] = dp[i - 1];
        continue;
      }
      if (i > 30) {
        dp[i] = std::min(dp[i - 1] + costs[0],
                         std::min(dp[i - 7] + costs[1], dp[i - 30] + costs[2]));
      } else if (i > 7) {
        dp[i] = std::min(dp[i - 1] + costs[0],
                         std::min(dp[i - 7] + costs[1], dp[0] + costs[2]));
      } else {
        dp[i] = std::min(dp[i - 1] + costs[0], dp[0] + costs[1]);
      }
    }
    return dp.back();
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}