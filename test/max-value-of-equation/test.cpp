#include <gtest/gtest.h>
#include <leetcode/editor/en/max-value-of-equation.cpp>

TEST(max_value_of_equation, demo) {
  vector<vector<int>> input{
      {1, 3}, {2, 0}, {5, 10}, {6, -10}
  };
  max_value_of_equation::Solution solution;
  EXPECT_EQ(solution.findMaxValueOfEquation(input, 1), 4);
}