//Given two integers n and k, return all possible combinations of k numbers 
//chosen from the range [1, n]. 
//
// You may return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: n = 4, k = 2
//Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
//Explanation: There are 4 choose 2 = 6 total combinations.
//Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to 
//be the same combination.
// 
//
// Example 2: 
//
// 
//Input: n = 1, k = 1
//Output: [[1]]
//Explanation: There is 1 choose 1 = 1 total combination.
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// Related Topics Backtracking 👍 5160 👎 164

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