#include <all.h>
namespace minimum_window_substring {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:

  string minWindow(string s, string t) {
    //pendingChar save not find char, queueChar save already find char
    std::multiset<char> pendingChar(t.begin(), t.end()), queueChar;
    //min store the minimum window, begin store the first target char, end store the next index of target char
    string minStr;
    size_t begin = s.find_first_of(t);
    if (begin == s.npos) {
      return minStr;
    }
    minStr = s + "*";
    size_t end = begin + 1;
    pendingChar.erase(s[begin]);
    queueChar.insert(s[begin]);
    for (; end < s.size(); ++end) {
      // all target has find
      if (pendingChar.empty()) {
        size_t curLen = end - begin;
        minStr = minStr.size() < curLen ? minStr : s.substr(begin, curLen);
        if (minStr.size() == t.size()) {
          return minStr;
        }

        pendingChar.insert(s[begin]);
        queueChar.erase(s[begin]);
      }
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}