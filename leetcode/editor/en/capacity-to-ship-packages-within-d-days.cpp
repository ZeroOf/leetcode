#include <all.h>
#include <numeric>
namespace capacity_to_ship_packages_within_d_days {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int shipWithinDays(vector<int> &weights, int days) {
    int cap = std::accumulate(weights.begin(), weights.end(), 0) / days;
    int possibleCap = 0;
    while ((possibleCap = shipWithinDays(weights, days, cap)) != cap) {
      cap = possibleCap;
    }
    return cap;
  }
  // try to ship, if cannot, return the least weight bigger than the current cap
  int shipWithinDays(vector<int> &weights, int days, int cap) {
    int possibleCap = INT32_MAX;
    int index = 0;
    while (days > 0) {
      int cargo = 0;
      while (index < weights.size() && cargo + weights[index] <= cap) {
        cargo += weights[index++];
      }
      if (index < weights.size()) {
        possibleCap = std::min(possibleCap, cargo + weights[index]);
      }
      days--;
    }
    if (index == weights.size()) {
      return cap;
    }
    return possibleCap;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}