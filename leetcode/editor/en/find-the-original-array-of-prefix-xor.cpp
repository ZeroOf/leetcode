#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<int> findArray(vector<int> &pref) {
    vector<int> ret(pref.size(), 0);
    ret[0] = pref[0];
    for (size_t i = 1; i < ret.size(); ++i) {
      ret[i] = pref[i - 1] ^ pref[i];
    }
    return ret;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(find_the_original_array_of_prefix_xor, demo) {
  Solution solution;
  vector<int> input{5, 2, 0, 3, 1};
  vector<int> expect{5, 7, 2, 3, 2};
  EXPECT_EQ(solution.findArray(input), expect);
}