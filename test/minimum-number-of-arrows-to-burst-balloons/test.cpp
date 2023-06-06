#include <gtest/gtest.h>
#include <leetcode/editor/en/minimum-number-of-arrows-to-burst-balloons.cpp>

TEST(MNOATBB, SORT) {
  vector<vector<int>> input{
      {10, 16}, {2, 8}, {1, 6}, {7, 12}
  };

  vector<vector<int>> output{
      {1, 6}, {2, 8}, {7, 12}, {10, 16}
  };
  std::sort(input.begin(), input.end());
  EXPECT_EQ(input, output);
}
TEST(MNOATBB, demo) {
  vector<vector<int>> input{
      {10, 16}, {2, 8}, {1, 6}, {7, 12}
  };
  minimum_number_of_arrows_to_burst_balloons::Solution solution;
  EXPECT_EQ(solution.findMinArrowShots(input), 2);
}
