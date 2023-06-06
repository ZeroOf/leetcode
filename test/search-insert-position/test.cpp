#include <gtest/gtest.h>
#include <leetcode/editor/en/search-insert-position.cpp>

class SIP : public testing::Test {
 public:
  search_insert_position::Solution solution_;
};

TEST_F(SIP, demo) {
  vector<int> input{1, 3, 5, 6};
  EXPECT_EQ(solution_.searchInsert(input, 5), 2);
}

TEST_F(SIP, demo1) {
  vector<int> input{1};
  EXPECT_EQ(solution_.searchInsert(input, 1), 0);
}
TEST_F(SIP, demo2) {
  vector<int> input{1};
  EXPECT_EQ(solution_.searchInsert(input, 0), 0);
}

TEST_F(SIP, demo3) {
  vector<int> input{1};
  EXPECT_EQ(solution_.searchInsert(input, 3), 1);
}

TEST_F(SIP, demo4) {
  vector<int> input{1, 3, 5, 6};
  EXPECT_EQ(solution_.searchInsert(input, 7), 4);
}
