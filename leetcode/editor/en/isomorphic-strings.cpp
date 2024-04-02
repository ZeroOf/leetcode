#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    std::map<char, char> s2t;
    std::map<char, char> t2s;
    for (int i = 0; i < s.size(); ++i) {
      if (s2t.find(s[i]) == s2t.end()) {
        s2t[s[i]] = t[i];
      } else if (s2t[s[i]] != t[i]) {
        return false;
      }

      if (t2s.find(t[i]) == t2s.end()) {
        t2s[t[i]] = s[i];
      } else if (t2s[t[i]] != s[i]) {
        return false;
      }

    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(isomorphic_strings, demo) {
  Solution solution;

  EXPECT_TRUE(solution.isIsomorphic("egg", "add"));
  EXPECT_TRUE(solution.isIsomorphic("paper", "title"));
  EXPECT_FALSE(solution.isIsomorphic("foo", "bar"));
  EXPECT_FALSE(solution.isIsomorphic("badc", "baba"));
}