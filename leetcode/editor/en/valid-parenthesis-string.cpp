#include <all.h>
#include <stack>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool checkValidString(string s) {
//    return topDownDP(s);
//    return down2TopDP(s);
//    return twoStack(s);
    return twoPointer(s);
  }

 private:
  // solution 1
  bool bruteForce(string s) {
    return backTrack(s, 0, 0);
  }

  bool backTrack(const string &s, int visit, int openingBracket) {
    if (visit == s.size()) {
      return openingBracket == 0;
    }
    if (')' == s[visit]) {
      if (openingBracket == 0) {
        return false;
      }
      return backTrack(s, visit + 1, openingBracket - 1);
    }

    if ('(' == s[visit]) {
      return backTrack(s, visit + 1, openingBracket + 1);
    }

    if (openingBracket > 0 && backTrack(s, visit + 1, openingBracket - 1)) {
      return true;
    }
    return backTrack(s, visit + 1, openingBracket) || backTrack(s, visit + 1, openingBracket + 1);
  }


  // solution 2
  bool topDownDP(const string &s) {
    // (index, openingBracket)
    vector<vector<int>> visit(s.size(), vector<int>(s.size(), -1));
    return topDownDP(0, 0, s, visit);
  }

  bool topDownDP(int index, int openingBracket, const string &s, vector<vector<int>> &visit) {
    if (index == s.size()) {
      return openingBracket == 0;
    }

    if (visit[index][openingBracket] != -1) {
      return visit[index][openingBracket];
    }
    if ('*' == s[index]) {
      // * as (
      if (topDownDP(index + 1, openingBracket + 1, s, visit)) {
        return true;
      }
      // * as )
      if (openingBracket > 0 && topDownDP(index + 1, openingBracket - 1, s, visit)) {
        return true;
      }
      // * as empty
      if (topDownDP(index + 1, openingBracket, s, visit)) {
        return true;
      }
    } else if ('(' == s[index] && topDownDP(index + 1, openingBracket + 1, s, visit)) {
      return true;
    } else if (')' == s[index] && openingBracket > 0 && topDownDP(index + 1, openingBracket - 1, s, visit)) {
      return true;
    }

    return visit[index][openingBracket] = false;
  }

  // solution 3
  static bool down2TopDP(const string &s) {
    // visit[i][j] = true means openBracket of s[i-1] can be j
    vector<vector<bool>> visit(s.size() + 1, vector<bool>(s.size() + 1, false));

    // when we don't visit any one yet, only 0 opening Bracket is possible
    visit[0][0] = true;

    // store the min and max count of previous char
    int minOpeningBracket = 0;
    int maxOpeningBracket = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        int j = minOpeningBracket;
        for (; j <= maxOpeningBracket; j++) {
          visit[i + 1][j + 1] = true;
        }
        minOpeningBracket += 1;
        maxOpeningBracket += 1;
      } else if (s[i] == ')') {
        if (maxOpeningBracket == 0) {
          return false;
        }
        for (int j = minOpeningBracket; j <= maxOpeningBracket; ++j) {
          visit[i + 1][j] = true;
        }
        if (minOpeningBracket > 0) {
          --minOpeningBracket;
          visit[i + 1][minOpeningBracket] = true;
        }
        maxOpeningBracket -= 1;
      }
        // '*'
      else {
        // * as empty
        for (int j = minOpeningBracket; j <= maxOpeningBracket; ++j) {
          visit[i + 1][j] = true;
        }
        if (minOpeningBracket > 0) {
          // * as )
          --minOpeningBracket;
          visit[i + 1][minOpeningBracket] = true;
        }
        if (maxOpeningBracket < s.size()) {
          // * as (
          ++maxOpeningBracket;
          visit[i + 1][maxOpeningBracket] = true;
        }
      }
    }
    return visit[s.size()][0] == true;
  }

  // solution 4 two stack
  bool twoStack(const string &s) {
    std::stack<int> openBracketIndex;
    std::stack<int> asteriskIndex;
    for (int i = 0; i < s.size(); ++i) {
      switch (s[i]) {
        case '(':openBracketIndex.push(i);
          break;
        case ')':
          if (!openBracketIndex.empty()) {
            openBracketIndex.pop();
          } else if (!asteriskIndex.empty()) {
            asteriskIndex.pop();
          } else {
            return false;
          }
          break;
        case '*':asteriskIndex.push(i);
          break;
      }
    }

    if (openBracketIndex.empty()) {
      return true;
    }
    while (!openBracketIndex.empty()) {
      if (asteriskIndex.empty() || asteriskIndex.top() < openBracketIndex.top()) {
        return false;
      }
      asteriskIndex.pop();
      openBracketIndex.pop();
    }
    return true;
  }

  bool twoPointer(const string &s) {
    int leftOpenCount = 0, rightCloseCount = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ')') {
        if (leftOpenCount == 0) {
          return false;
        }
        --leftOpenCount;
      } else {
        ++leftOpenCount;
      }
      if (s[s.size() - i - 1] == '(') {
        if (rightCloseCount == 0) {
          return false;
        }
        --rightCloseCount;
      } else {
        ++rightCloseCount;
      }
    }
    return leftOpenCount >= 0 && rightCloseCount >= 0;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(valid_parenthesis_string, demo) {
  Solution solution;
  EXPECT_TRUE(solution.checkValidString("()"));
  EXPECT_TRUE(solution.checkValidString("(*)"));
  EXPECT_TRUE(solution.checkValidString("(*))"));
}