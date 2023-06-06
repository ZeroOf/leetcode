#include <all.h>
namespace can_place_flowers {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    if (n == 0) {
      return true;
    }
    int cur = 0;
    while (cur < flowerbed.size()) {
      if (cur - 1 >= 0 && flowerbed[cur - 1] == 1) {
        cur++;
        continue;
      }

      if (cur + 1 < flowerbed.size() && flowerbed[cur + 1] == 1) {
        cur += 3;
        continue;
      }

      if (flowerbed[cur] == 1) {
        cur += 2;
        continue;
      }

      if (--n == 0) {
        return true;
      }
      cur += 2;
    }
    return false;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}