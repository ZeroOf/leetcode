#include <gtest/gtest.h>
#include <leetcode/editor/en/minimum-window-substring.cpp>

class MWSTest : public ::testing::Test {
 public:
  minimum_window_substring::Solution solution_;
};

TEST_F(MWSTest, demo) {
  string input("ADOBECODEBANC");
  EXPECT_EQ(solution_.minWindow(input, "ABC"), "BANC");
}

TEST_F(MWSTest, demo2) {
  string input("a");
  EXPECT_EQ(solution_.minWindow(input, "a"), "a");
}

TEST_F(MWSTest, demo3) {
  string input("a");
  EXPECT_EQ(solution_.minWindow(input, "aa"), "");
}

TEST_F(MWSTest, demo4) {
  string input("aa");
  EXPECT_EQ(solution_.minWindow(input, "aa"), "aa");
}