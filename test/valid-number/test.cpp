#include <gtest/gtest.h>
#include <leetcode/editor/en/valid-number.cpp>

TEST(valid_number, int) {
  valid_number::Solution solution;
  EXPECT_EQ(solution.isNumber("1"), true);
  EXPECT_EQ(solution.isNumber("+1"), true);
  EXPECT_EQ(solution.isNumber("-1"), true);
  EXPECT_EQ(solution.isNumber("s1"), false);
  EXPECT_EQ(solution.isNumber("1s"), false);
  EXPECT_EQ(solution.isNumber("+1s"), false);
  EXPECT_EQ(solution.isNumber("-1s"), false);
}
TEST(valid_number, decimal) {
  valid_number::Solution solution;
  EXPECT_EQ(solution.isNumber("1."), true);
  EXPECT_EQ(solution.isNumber("."), false);
  EXPECT_EQ(solution.isNumber("+."), false);
}
