#include <all.h>
namespace search_insert_position {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int searchInsert(vector<int> &nums, int target) {
    int head = 0, tail = nums.size() - 1;
    while (head <= tail) {
      // when tail = head + 1, mid is head
      int mid = (head + tail) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] < target) {
        head = mid + 1;
      } else {
        tail = mid - 1;
      }
    }
    return head;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}