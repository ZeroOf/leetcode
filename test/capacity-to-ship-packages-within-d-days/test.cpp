#include <gtest/gtest.h>
#include <leetcode/editor/en/capacity-to-ship-packages-within-d-days.cpp>

class CTSPWDD : public testing::Test {
 public:
  capacity_to_ship_packages_within_d_days::Solution solution_;
};

TEST_F(CTSPWDD, demo) {
  vector<int> input{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  EXPECT_EQ(solution_.shipWithinDays(input, 5), 15);
}