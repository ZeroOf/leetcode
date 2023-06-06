#include <gtest/gtest.h>
#include <leetcode/editor/en/unique-paths-iii.cpp>

TEST(UNIQUE_PATH_III, demo) {
  vector<vector<int>> input = {
      {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}
  };
  unique_paths_iii::Solution solution;
  EXPECT_EQ(solution.uniquePathsIII(input), 2);
}

TEST(UNIQUE_PATH_III, demo2) {
  vector<vector<int>> input = {
      {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}
  };
  unique_paths_iii::Solution solution;
  EXPECT_EQ(solution.uniquePathsIII(input), 4);
}

TEST(UNIQUE_PATH_III, unique) {
  vector<vector<int>> input = {
      {1, 2}
  };
  unique_paths_iii::Solution solution;
  EXPECT_EQ(solution.uniquePathsIII(input), 1);
}