#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  long long wonderfulSubstrings(string word) {
    long long ans = 0;
    std::map<uint16_t, int> mask2Count;
    mask2Count[0] = 1;
    uint16_t mask = 0;
    for (auto c : word) {

      // flip the parity of the c-th bit in the running prefix mask
      mask ^= 1 << (c - 'a');

      // count smaller prefixes that create substrings no odd occurring leeters
      ans += mask2Count[mask];

      // loop through every possible letter that can appear an odd number of times in a substring
      for (int i = 0; i < 10; i++) {
        ans += mask2Count[mask ^ (1 << i)];
      }
      mask2Count[mask]++;
    }
    return ans;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


// test case
TEST(number_of_wonderful_substrings, demo) {
  Solution solution;
  EXPECT_EQ(solution.wonderfulSubstrings("aba"), 4);
  EXPECT_EQ(solution.wonderfulSubstrings("aabb"), 9);
  EXPECT_EQ(solution.wonderfulSubstrings("he"), 2);
  EXPECT_EQ(solution.wonderfulSubstrings("hea"), 3);
}