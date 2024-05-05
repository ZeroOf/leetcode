#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int longestIdealString(string s, int k) {
//    return towDown(s, k);
    return DownTop(s, k);
  }

 private:
  // solution 2
  int DownTop(const string &s, int k) {
    std::vector<int> dp(26, 0);
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      int curr = s[i] - 'a';
      int best = 0;
      for (int prev = 0; prev < 26; ++prev) {
        if (abs(prev - curr) <= k) {
          best = max(best, dp[prev]);
        }
      }

      dp[curr] = best + 1;
      res = max(res, dp[curr]);
    }
    return res;
  }

  // solution 1
  int towDown(string &s, int k) {
    std::vector<std::vector<int>> char2length(26, vector<int>(s.size(), NEVER_VISIT));
    int res = 0;
    int N = s.size();
    for (int i = 0; i < 26; ++i) {
      res = std::max(res, dfs(s, char2length, N - 1, i, k));
    }
    return res;
  }

  int dfs(string &s, vector<vector<int>> &char2length, int index, int endChar, int k) {
    if (NEVER_VISIT != char2length[endChar][index]) {
      return char2length[endChar][index];
    }

    char2length[endChar][index] = 0;
    bool isMatch = (endChar + 'a') == s[index];
    if (isMatch) {
      char2length[endChar][index] = 1;
    }

    if (index > 0) {
      // not end with s[index]
      char2length[endChar][index] = dfs(s, char2length, index - 1, endChar, k), char2length[endChar][index];
      // end with s[index]
      if (isMatch) {
        auto firstEnd = endChar - k > 0 ? endChar - k : 0;
        auto lastEnd = endChar + k > 25 ? 25 : endChar + k;
        for (int nextEnd = firstEnd; nextEnd <= lastEnd; ++nextEnd) {
          char2length[endChar][index] = max(char2length[endChar][index],
                                            dfs(s, char2length, index - 1, nextEnd, k) + 1);
        }
      }
    }
    return char2length[endChar][index];
  }

  static constexpr int NEVER_VISIT = -1;
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(longest_ideal_subsequence, demo) {
  Solution solution;
  EXPECT_EQ(solution.longestIdealString("acfgbd", 2), 4);
  EXPECT_EQ(solution.longestIdealString("abcd", 3), 4);
  EXPECT_EQ(solution.longestIdealString("eduktdb", 15), 5);
}