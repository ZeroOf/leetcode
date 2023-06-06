#include <all.h>
namespace number_of_zero_filled_subarrays {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long zeroCount = 0;
    long long ret = 0;
    for (auto num : nums) {
      if (0 == num) {
        ret += ++zeroCount;
      } else {
        zeroCount = 0;
      }
    }
    return ret;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}