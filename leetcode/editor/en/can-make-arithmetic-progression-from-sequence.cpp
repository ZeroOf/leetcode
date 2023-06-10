#include <all.h>
namespace can_make_arithmetic_progression_from_sequence {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int> &arr) {
    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());
    if (min == max) {
      return true;
    }
    int n = arr.size();

    if ((max - min) % (n - 1) != 0) {
      return false;
    }
    int diff = (max - min) / (n - 1);
    int i = 0;
    while (i < n) {
      if (0 != (arr[i] - min) % diff) {
        return false;
      }
      int j = (arr[i] - min) / diff;
      if (i == j) {
        ++i;
        continue;
      }
      if (arr[j] == arr[i]) {
        return false;
      }
      swap(arr[i], arr[j]);
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}

TEST(can_make_arithmetic_progression_from_sequence, demo) {
  can_make_arithmetic_progression_from_sequence::Solution solution;
  vector<int> input{3, 4, 2, 1};
  EXPECT_TRUE(solution.canMakeArithmeticProgression(input));
}