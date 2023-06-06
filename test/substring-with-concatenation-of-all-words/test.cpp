#include <gtest/gtest.h>
#include <leetcode/editor/en/substring-with-concatenation-of-all-words.cpp>

TEST(VN, range) {
  substring_with_concatenation_of_all_words::Solution solution;
  {
    string input("barfoothefoobarman");
    vector<string> target{"foo", "bar"};
    vector<int> expect{0, 9};
    EXPECT_EQ(solution.findSubstring(input, target), expect);
  }
  {
    string input("wordgoodgoodgoodbestword");
    vector<string> target{"word", "good", "best", "good"};
    vector<int> expect{8};
    EXPECT_EQ(solution.findSubstring(input, target), expect);
  }
}