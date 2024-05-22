#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> singleRes;
    vector<vector<int8_t>> dp(s.size(), vector<int8_t>(s.size(), -1));
    for (int i = 0; i < s.size(); ++i) {
      auto cur = s.substr(0, i - 0 + 1);
      if (isPalindrome(s, dp, 0, i)) {
        singleRes.push_back(cur);
        partition(s, singleRes, res, i + 1, dp);
        singleRes.pop_back();
      }
    }
    return res;
  }

 private:
  bool isPalindrome(const string &s, vector<vector<int8_t>> &dp, int start, int end) {
    if (dp[start][end] != -1) {
      return dp[start][end];
    }
    int left = start, right = end;
    while (left < right) {
      if (s[left] != s[right]) {
        dp[start][end] = false;
        return false;
      }
      left++;
      right--;
    }
    dp[start][end] = true;
    return true;
  }

  void partition(const string &s,
                 vector<string> &singleRes,
                 vector<vector<string>> &res,
                 int curIdx,
                 vector<vector<int8_t>> &dp) {
    if (curIdx == s.size()) {
      res.push_back(singleRes);
      return;
    }
    for (int i = curIdx; i < s.size(); ++i) {
      auto nextStr = s.substr(curIdx, i - curIdx + 1);
      if (isPalindrome(s, dp, curIdx, i)) {
        singleRes.push_back(nextStr);
        partition(s, singleRes, res, i + 1, dp);
        singleRes.pop_back();
      }
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(palindrome_partitioning, demo) {
  Solution solution;
  auto res = solution.partition("aab");
  auto expect = vector<vector<string>>{{"a", "a", "b"}, {"aa", "b"}};
  ASSERT_EQ(res, expect);

  res = solution.partition("a");
  expect = vector<vector<string>>{{"a"}};
  ASSERT_EQ(res, expect);
}