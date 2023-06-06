//You are given a string s and an array of strings words of the same length. 
//Return all starting indices of substring(s) in s that is a concatenation of each 
//word in words exactly once, in any order, and without any intervening characters. 
//
//
// You can return the answer in any order. 
//
// 
// Example 1: 
//
// 
//Input: s = "barfoothefoobarman", words = ["foo","bar"]
//Output: [0,9]
//Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" 
//respectively.
//The output order does not matter, returning [9,0] is fine too.
// 
//
// Example 2: 
//
// 
//Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//Output: []
// 
//
// Example 3: 
//
// 
//Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//Output: [6,9,12]
// 
//
// 
// Constraints: 
//
// 
// 1 <= s.length <= 10⁴ 
// 1 <= words.length <= 5000 
// 1 <= words[i].length <= 30 
// s and words[i] consist of lowercase English letters. 
// 
//
// Related Topics Hash Table String Sliding Window 👍 2465 👎 1995

#include <all.h>
namespace substring_with_concatenation_of_all_words {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string> &words) {
    multiset<string> wordsSet(words.begin(), words.end());
    size_t wordLen = words[0].size();
    size_t wordsNum = words.size();
    vector<int> result;
    if(wordLen * wordsNum > s.size()) {
      return result;
    }
    for (int i = 0; i <= s.size() - wordLen * wordsNum; ++i) {
      if (isMatch(s.substr(i, wordLen * wordsNum), wordsSet, wordLen)) {
        result.push_back(i);
      }
    }
    return result;
  }
 private:
  bool isMatch(string words, multiset<string> target, size_t wordLen) {
    for (size_t i = 0; i < words.size(); i += wordLen) {
      string word = words.substr(i, wordLen);
      auto iWord = target.find(word);
      if (target.end() == iWord) {
        return false;
      }
      target.erase(iWord);
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


}