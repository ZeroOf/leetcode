#include <gtest/gtest.h>
#include <leetcode/editor/en/largest-perimeter-triangle.cpp>

class LPTTest : public ::testing::Test {
 public:
  largest_perimeter_triangle::Solution solution_;
};

TEST_F(LPTTest, demo) {
  vector<int> input{2,1,2};
  EXPECT_EQ(solution_.largestPerimeter(input), 5);
}
TEST_F(LPTTest, demo1) {
  vector<int> input{3,2,3,4};
  EXPECT_EQ(solution_.largestPerimeter(input), 10);
}
