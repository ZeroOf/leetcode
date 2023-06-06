#include <all.h>
namespace single_element_in_a_sorted_array {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int singleNonDuplicate(vector<int> &nums) {
    int ret = 0;
    for (auto num : nums) {
      ret ^= num;
    }
    return ret;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}