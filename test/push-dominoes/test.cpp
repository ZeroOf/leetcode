#include <gtest/gtest.h>
#include <leetcode/editor/en/push-dominoes.cpp>

class PushDominoesTest : public ::testing::Test {
 public:
  push_dominoes::Solution solution_;
};

TEST_F(PushDominoesTest, demo) {
  string output("RR.L");
  EXPECT_EQ(solution_.pushDominoes("RR.L"), output);
}

TEST_F(PushDominoesTest, demo2) {
  string output("RRR.L");
  EXPECT_EQ(solution_.pushDominoes("R.R.L"), output);
}
