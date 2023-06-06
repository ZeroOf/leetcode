#include <gtest/gtest.h>
#include <leetcode/editor/en/set-matrix-zeroes.cpp>

class SMZ : public ::testing::Test {

 protected:
  void SetUp() override {

  }
  set_matrix_zeroes::Solution solution_;
};

TEST_F(SMZ, demo) {
  vector<vector<int>> input{ {1,1,1},{1,0,1},{1,1,1} };
  vector<vector<int>> output{ {1,0,1},{0,0,0},{1,0,1} };
  solution_.setZeroes(input);
  EXPECT_EQ(input, output);
}