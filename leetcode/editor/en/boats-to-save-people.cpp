#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int numRescueBoats(vector<int> &people, int limit) {
    std::sort(people.begin(), people.end());
    // start and end is not visited
    size_t end = people.size() - 1, start = 0;
    int res = 0;
    while (end > start) {
      if (people[end] + people[start] <= limit) {
        start++;
      }
      end--;
      res++;
    }
    if (end == start) {
      res++;
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(boats_to_save_people, demo) {
  Solution solution;

  vector<int> people = {1, 2};
  EXPECT_EQ(solution.numRescueBoats(people, 3), 1);

  people = {3, 2, 2, 1};
  EXPECT_EQ(solution.numRescueBoats(people, 3), 3);

  EXPECT_EQ(solution.numRescueBoats(people, 4), 2);

  people = {3, 5, 3, 4};
  EXPECT_EQ(solution.numRescueBoats(people, 5), 4);
}