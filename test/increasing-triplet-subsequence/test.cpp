#include <gtest/gtest.h>
#include <leetcode/editor/en/increasing-triplet-subsequence.cpp>

class ITSTest : public ::testing::Test {
 public:
  increasing_triplet_subsequence::Solution solution_;
};

TEST_F(ITSTest, demo) {
  vector<int> input{1, 2, 3, 4, 5};
  EXPECT_TRUE(solution_.increasingTriplet(input));
}
TEST_F(ITSTest, demo1) {
  vector<int> input{2,1,5,0,4,6};
  EXPECT_TRUE(solution_.increasingTriplet(input));
}
