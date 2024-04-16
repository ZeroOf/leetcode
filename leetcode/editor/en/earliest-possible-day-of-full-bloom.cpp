#include <all.h>

namespace earliest_possible_day_of_full_bloom {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
    // use set for sort flower seed by growTime
    auto compare = [&plantTime, &growTime](int lhs, int rhs) {
      if (growTime[lhs] > growTime[rhs]) {
        return true;
      }
      if (growTime[lhs] == growTime[rhs]) {
        return plantTime[lhs] == plantTime[rhs] ? lhs > rhs : plantTime[lhs] > plantTime[rhs];
      }
      return false;
    };
    std::set<int, decltype(compare)> flowersOrderByGrowTime(compare);
    for (int i = 0; i < plantTime.size(); ++i) {
      flowersOrderByGrowTime.insert(i);
    }
    int maxDay = 0;
    int plantDay = 0;
    for (auto index : flowersOrderByGrowTime) {
      plantDay += plantTime[index];
      maxDay = max(maxDay, plantDay + growTime[index]);
    }
    return maxDay;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}

TEST(earliest_possible_day_of_full_bloom, demo) {
  earliest_possible_day_of_full_bloom::Solution solution;
  std::vector<int> plantTime{1,4,3};
  std::vector<int> growTime{2,3,1};

  EXPECT_EQ(solution.earliestFullBloom(plantTime, growTime), 9);

  plantTime = {1,2,3,2};
  growTime = {2,1,2,1};
  EXPECT_EQ(solution.earliestFullBloom(plantTime, growTime), 9);

  plantTime = {1};
  growTime = {1};
  EXPECT_EQ(solution.earliestFullBloom(plantTime, growTime), 2);
}