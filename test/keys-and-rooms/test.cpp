#include <gtest/gtest.h>
#include <leetcode/editor/en/keys-and-rooms.cpp>

TEST(keys_and_rooms, demo) {
  vector<vector<int>> input{
      {1}, {2}, {3}, {}
  };
  keys_and_rooms::Solution solution;
  EXPECT_EQ(solution.canVisitAllRooms(input), true);
}
TEST(keys_and_rooms, demo2) {
  vector<vector<int>> input{
      {1,3},{3,0,1},{2},{0}
  };
  keys_and_rooms::Solution solution;
  EXPECT_FALSE(solution.canVisitAllRooms(input));
}
