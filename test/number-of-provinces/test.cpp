#include <gtest/gtest.h>
#include <leetcode/editor/en/number-of-provinces.cpp>

TEST(number_of_provinces, demo) {
  number_of_provinces::Solution solution;
  vector<vector<int>> input{
      {1, 1, 0},
      {1, 1, 0},
      {0, 0, 1}
  };
  EXPECT_EQ(solution.findCircleNum(input), 2);
}
