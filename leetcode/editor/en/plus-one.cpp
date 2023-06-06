#include <all.h>
namespace plus_one {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
      if (*it < 9) {
        *it += 1;
        return digits;
      }
      *it = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}