//Given an array of strings words and a width maxWidth, format the text such 
//that each line has exactly maxWidth characters and is fully (left and right) 
//justified. 
//
// You should pack your words in a greedy approach; that is, pack as many words 
//as you can in each line. Pad extra spaces ' ' when necessary so that each line 
//has exactly maxWidth characters. 
//
// Extra spaces between words should be distributed as evenly as possible. If 
//the number of spaces on a line does not divide evenly between words, the empty 
//slots on the left will be assigned more spaces than the slots on the right. 
//
// For the last line of text, it should be left-justified, and no extra space 
//is inserted between words. 
//
// Note: 
//
// 
// A word is defined as a character sequence consisting of non-space characters 
//only. 
// Each word's length is guaranteed to be greater than 0 and not exceed 
//maxWidth. 
// The input array words contains at least one word. 
// 
//
// 
// Example 1: 
//
// 
//Input: words = ["This", "is", "an", "example", "of", "text", "justification."]
//, maxWidth = 16
//Output:
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//] 
//
// Example 2: 
//
// 
//Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 
//16
//Output:
//[
//  "What   must   be",
//  "acknowledgment  ",
//  "shall be        "
//]
//Explanation: Note that the last line is "shall be    " instead of "shall     
//be", because the last line must be left-justified instead of fully-justified.
//Note that the second line is also left-justified because it contains only one 
//word. 
//
// Example 3: 
//
// 
//Input: words = ["Science","is","what","we","understand","well","enough","to",
//"explain","to","a","computer.","Art","is","everything","else","we","do"], 
//maxWidth = 20
//Output:
//[
//  "Science  is  what we",
//  "understand      well",
//  "enough to explain to",
//  "a  computer.  Art is",
//  "everything  else  we",
//  "do                  "
//] 
//
// 
// Constraints: 
//
// 
// 1 <= words.length <= 300 
// 1 <= words[i].length <= 20 
// words[i] consists of only English letters and symbols. 
// 1 <= maxWidth <= 100 
// words[i].length <= maxWidth 
// 
//
// Related Topics Array String Simulation 👍 1981 👎 3170

#include <all.h>
namespace text_justification {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  /* 2 part
   * 1. fill line with word, while word in words, if sum of word length more than maxWidth or no word in words
   * 2. calculate space num = (maxWidth - sum of word) / (number of word - 1)
   *    if space num * number of word != maxWidth, less num = maxWidth - space num * number of word
   *
   */
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> result;
    size_t index = 0;
    while (index < words.size()) {
      vector<string> wordsOfLine;
      size_t length = 0, wordNum = 0;
      while (index < words.size() && length < maxWidth) {
        if (length + words[index].length() + wordNum > maxWidth) {
          break;
        }
        wordsOfLine.push_back(words[index]);
        length += words[index].length();
        ++index;
        ++wordNum;
      }

      string line;
      if (wordsOfLine.size() == 1) {
        line = wordsOfLine.front() + string(maxWidth - wordsOfLine.front().size(), ' ');
      } else if (index < words.size()) {
        size_t spaceNum = (maxWidth - length) / (wordNum - 1);
        size_t plusNum = (maxWidth - length) % (wordNum - 1);
        size_t i = 0;
        for (; i < plusNum; ++i) {
          line = line + wordsOfLine[i] + string(spaceNum + 1, ' ');
        }
        for (; i < wordsOfLine.size() - 2; ++i) {
          line = line + wordsOfLine[i] + string(spaceNum, ' ');
        }
        line += wordsOfLine[wordNum - 2];
        line += string(maxWidth - line.size() - wordsOfLine.back().size(), ' ');
        line += wordsOfLine.back();
      } else {
        for (size_t i = 0; i < wordNum - 1; ++i) {
          line = line + wordsOfLine[i] + " ";
        }
        line += wordsOfLine.back();
        line += string(maxWidth - line.size(), ' ');
      }
      result.push_back(line);
    }
    return result;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}