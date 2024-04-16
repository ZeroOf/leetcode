#include <all.h>
#include <stack>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    std::stack<int> leftParenthesis;
    std::set<int> toDelete;
    for (int i = 0; i < s.size(); ++i) {
      if ('(' == s[i]) {
        leftParenthesis.push(i);
      } else if (')' == s[i]) {
        if (leftParenthesis.empty()) {
          toDelete.insert(i);
        } else {
          leftParenthesis.pop();
        }
      }
    }

    while (!leftParenthesis.empty()) {
      toDelete.insert(leftParenthesis.top());
      leftParenthesis.pop();
    }
    for (auto rit = toDelete.rbegin(); rit != toDelete.rend(); ++rit) {
      s.erase(*rit,1);
    }
    return s;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(minimum_remove_to_make_valid_parentheses, demo) {
  Solution solution;
  EXPECT_EQ(solution.minRemoveToMakeValid("lee(t(c)o)de)"), "lee(t(c)o)de");
  EXPECT_EQ(solution.minRemoveToMakeValid("a)b(c)d"), "ab(c)d");
  EXPECT_EQ(solution.minRemoveToMakeValid("))(("), "");
}