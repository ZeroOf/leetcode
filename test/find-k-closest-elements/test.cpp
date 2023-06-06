#include <gtest/gtest.h>
#include <leetcode/editor/en/find-k-closest-elements.cpp>

class FKCE : public ::testing::Test {
 public:
  find_k_closest_elements::Solution solution_;
};

TEST_F(FKCE, demo) {
  vector<int> input{1, 2, 3, 4, 5};
  vector<int> output{1, 2, 3, 4};
  EXPECT_EQ(solution_.findClosestElements(input, 4, 3), output);
}

TEST_F(FKCE, demo2) {
  vector<int> input{1};
  vector<int> output{1};
  EXPECT_EQ(solution_.findClosestElements(input, 1, 3), output);
}

TEST_F(FKCE, demo3) {
  vector<int> input{5};
  vector<int> output{5};
  EXPECT_EQ(solution_.findClosestElements(input, 1, 3), output);
}
TEST_F(FKCE, demo4) {
  vector<int> input{1, 2, 3, 4, 5};
  vector<int> output{1, 2, 3, 4};
  EXPECT_EQ(solution_.findClosestElements(input, 4, -1), output);
}
TEST_F(FKCE, demo5) {
  vector<int> input{-2, -1, 1, 2, 3, 4, 5};
  vector<int> output{-2, -1, 1, 2, 3, 4, 5};
  EXPECT_EQ(solution_.findClosestElements(input, 7, 3), output);
}
TEST_F(FKCE, demo6) {
  vector<int> input{1, 2, 2, 2, 5, 5, 5, 8, 9, 9};
  vector<int> output{1, 2, 2, 2};
  EXPECT_EQ(solution_.findClosestElements(input, 4, 0), output);
}
TEST_F(FKCE, demo7) {
  vector<int> input{1};
  vector<int> output{1};
  EXPECT_EQ(solution_.findClosestElements(input, 1, 0), output);
}
TEST_F(FKCE, demo8) {
  vector<int> input{0,2,2,3,4,6,7,8,9,9};
  vector<int> output{3,4,6,7};
  EXPECT_EQ(solution_.findClosestElements(input, 4, 5), output);
}
TEST_F(FKCE, demo9) {
  vector<int> input{0,1,2,2,2,3,6,8,8,9};
  vector<int> output{3,6,8,8,9};
  EXPECT_EQ(solution_.findClosestElements(input, 5, 9), output);
}
TEST_F(FKCE, demo10) {
  vector<int> input{3,5,8,10};
  vector<int> output{8,10};
  EXPECT_EQ(solution_.findClosestElements(input, 2, 15), output);
}
