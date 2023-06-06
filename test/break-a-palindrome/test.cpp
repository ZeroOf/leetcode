#include <gtest/gtest.h>
#include <leetcode/editor/en/break-a-palindrome.cpp>

class break_a_palindrome_test : public ::testing::Test {
 public:
  break_a_palindrome::Solution solution_;
};

TEST_F(break_a_palindrome_test, demo) {
  EXPECT_EQ(solution_.breakPalindrome("a"), "");
}