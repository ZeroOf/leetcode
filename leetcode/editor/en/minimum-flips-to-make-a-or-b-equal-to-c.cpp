#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int minFlips(int a, int b, int c) {
    // at a specific bit, if a | b != c
    // c == 1, a == b == 0, need 1 flit
    // c == 0, a == 1 or b == 1 or a == 1 and b == 1
    // use d = (a|b ^ c) check where a|b != c
    // all 1 in d & c add 1 to result
    // all 1 in d & a add 1 to result
    // all 1 in d & b add 1 to result
    int d = (a | b) ^ c;
    return count1(a & d) + count1(b & d) + count1(c & d);
  }

  int count1(int num) {
    int count = 0;
    while (num > 0) {
      ++count;
      num = num & (num - 1);
    }
    return count;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(minimum_flips_to_make_a_or_b_equal_to_c, demo) {
  Solution solution;
  EXPECT_EQ(solution.minFlips(2, 6, 5), 3);
  EXPECT_EQ(solution.minFlips(4, 2, 7), 1);
  EXPECT_EQ(solution.minFlips(1, 2, 3), 0);
}