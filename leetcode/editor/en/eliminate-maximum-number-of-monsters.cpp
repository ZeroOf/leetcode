#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
    std::array<int, 100000> count{0};
    for (size_t i = 0; i < dist.size(); ++i) {
      count[(dist[i] - 1) / speed[i]]++;
    }
    int visited = 0;
    for (size_t i = 0; i < count.size() && visited < dist.size(); ++i) {
      if (visited + count[i] > i + 1) {
        return i + 1;
      }
      visited += count[i];
    }
    return dist.size();
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(eliminate_maximum_number_of_monsters, demo) {
  vector<int> dist{1, 3, 4}, speed{1, 1, 1};
  Solution solution;
  EXPECT_EQ(solution.eliminateMaximum(dist, speed), 3);
}

TEST(eliminate_maximum_number_of_monsters, demo2) {
  vector<int> dist{1, 1, 2, 3}, speed{1, 1, 1, 1};
  Solution solution;
  EXPECT_EQ(solution.eliminateMaximum(dist, speed), 1);
}

TEST(eliminate_maximum_number_of_monsters, demo3) {
  vector<int> dist{3, 2, 4}, speed{5, 3, 2};
  Solution solution;
  EXPECT_EQ(solution.eliminateMaximum(dist, speed), 1);
}

TEST(eliminate_maximum_number_of_monsters, demo4) {
  vector<int> dist{4, 2, 8}, speed{2, 1, 4};
  Solution solution;
  EXPECT_EQ(solution.eliminateMaximum(dist, speed), 2);
}
