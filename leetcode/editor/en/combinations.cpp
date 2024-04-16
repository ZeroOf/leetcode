#include <all.h>

namespace combinations {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> tmp;
    vector<vector<int>> res;
    combine(n, 1, k, tmp, res);
    return res;
  }

  void combine(int n, int start, int remain, vector<int> tmp, vector<vector<int>> &res) {
    if (remain == 0) {
      res.push_back(tmp);
      return;
    }
    for (int i = start; i <= n - remain + 1; ++i) {
      tmp.push_back(i);
      combine(n, i + 1, remain - 1, tmp, res);
      tmp.pop_back();
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}