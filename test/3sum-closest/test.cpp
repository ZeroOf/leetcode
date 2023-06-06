#include <gtest/gtest.h>
#include <leetcode/editor/en/3sum-closest.cpp>

class ThreeSumClosestTest : public ::testing::Test {
 public:
  three_sum_closest::Solution solution_;
};

TEST_F(ThreeSumClosestTest, demo1) {
  std::vector<int> input{-1, 2, 1, -4};
  EXPECT_EQ(solution_.threeSumClosest(input, 1), 2);
}

TEST_F(ThreeSumClosestTest, demo2) {
  std::vector<int> input{0, 2, 1, -3};
  EXPECT_EQ(solution_.threeSumClosest(input, 1), 0);
}

TEST_F(ThreeSumClosestTest, demo3) {
  std::vector<int> input{1, 1, 1, 0};
  EXPECT_EQ(solution_.threeSumClosest(input, 100), 3);
}