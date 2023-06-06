//A valid number can be split up into these components (in order): 
//
// 
// A decimal number or an integer. 
// (Optional) An 'e' or 'E', followed by an integer. 
// 
//
// A decimal number can be split up into these components (in order): 
//
// 
// (Optional) A sign character (either '+' or '-'). 
// One of the following formats: 
// 
// One or more digits, followed by a dot '.'. 
// One or more digits, followed by a dot '.', followed by one or more digits. 
// A dot '.', followed by one or more digits. 
// 
// 
//
// An integer can be split up into these components (in order): 
//
// 
// (Optional) A sign character (either '+' or '-'). 
// One or more digits. 
// 
//
// For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.1
//4", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], 
//while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "-
//-6", "-+3", "95a54e53"]. 
//
// Given a string s, return true if s is a valid number. 
//
// 
// Example 1: 
//
// 
//Input: s = "0"
//Output: true
// 
//
// Example 2: 
//
// 
//Input: s = "e"
//Output: false
// 
//
// Example 3: 
//
// 
//Input: s = "."
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 20 
// s consists of only English letters (both uppercase and lowercase), digits (0-
//9), plus '+', minus '-', or dot '.'. 
// 
//
// Related Topics String 👍 695 👎 1234

#include <all.h>
namespace valid_number {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool isNumber(string s) {
    if(s.empty()) {
      return false;
    }
    size_t ePos = s.find('e');
    if (ePos == string::npos) {
      ePos = s.find('E');
    }
    if (ePos != string::npos) {
      if (!isInteger(s.substr(ePos+1))) {
        return false;
      }
      s = s.substr(0, ePos);
    }
    size_t dotPos = s.find('.');
    if (dotPos != string::npos) {
      return isDecimal(s);
    }
    else {
      return isInteger(s);
    }
  }
 private:
  bool isInteger(string input) {
    if (input.empty()) {
      return false;
    }
    if (input[0] == '-' || input[0] == '+') {
      input = input.substr(1);
    }
    return isDigit(input);
  }

  bool isDigit(string input) {
    if (input.empty()) {
      return false;
    }
    for (const auto &c : input) {
      if (!isdigit(c)) {
        return false;
      }
    }
    return true;
  }

  bool isDecimal(string input) {
    if (input.empty() || input.size() == 1) {
      return false;
    }
    if (input[0] == '-' || input[0] == '+') {
      input = input.substr(1);
      return isDecimal(input);
    }
    size_t dotPos = input.find('.');
    if (dotPos == string::npos) {
      return false;
    }
    if (dotPos != 0) {
      if (!isInteger(input.substr(0, dotPos))) {
        return false;
      }
    }
    if (!input.substr(dotPos + 1).empty()&&!isDigit(input.substr(dotPos + 1))) {
      return false;
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}