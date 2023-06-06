#include <gtest/gtest.h>
#include <leetcode/editor/en/longest-cycle-in-a-graph.cpp>

TEST(longest_cycle_in_a_graph, demo) {
  vector<int> input{3, 3, 4, 2, 3};
  longest_cycle_in_a_graph::Solution solution;
  EXPECT_EQ(solution.longestCycle(input), 3);
}

TEST(longest_cycle_in_a_graph, demo2) {
  vector<int> input{2, -1, 3, 1};
  longest_cycle_in_a_graph::Solution solution;
  EXPECT_EQ(solution.longestCycle(input), -1);
}