#include <gtest/gtest.h>
#include <leetcode/editor/en/combinations.cpp>

class CBTest : public ::testing::Test {
 public:
  combinations::Solution solution_;
};

TEST_F(CBTest, demo) {
  vector<vector<int>> output{{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
  EXPECT_EQ(solution_.combine(4, 2), output);
}
TEST_F(CBTest, demo1) {
  vector<vector<int>> output{{1}};
  EXPECT_EQ(solution_.combine(1, 1), output);
}
