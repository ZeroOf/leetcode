#include <gtest/gtest.h>
#include <leetcode/editor/en/sort-colors.cpp>

class SortColor : public ::testing::Test {
 protected:
  void SetUp() override {
    std::cout << __func__ << std::endl;
  }
  sort_colors::Solution solution_;
};

TEST_F(SortColor, 201) {
  vector<int> input{2, 0, 1};
  solution_.sortColors(input);
  vector<int> output{0, 1, 2};
  EXPECT_EQ(input, output);
}
TEST_F(SortColor, 102) {
  vector<int> input{1, 0, 2};
  solution_.sortColors(input);
  vector<int> output{0, 1, 2};
  EXPECT_EQ(input, output);
}
