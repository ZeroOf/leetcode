#include <all.h>
#include <climits>
namespace max_value_of_equation {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  // yi - xi + yj + xj
  // for each point, we need to find the max value of yi - xi
  int findMaxValueOfEquation(vector<vector<int>> &points, int k) {
    int max = INT_MIN;
    // {yi - xi, xi}
    std::priority_queue<std::pair<int, int>> queue;
    for (auto &point : points) {
      while (!queue.empty()) {
        if (point[0] - queue.top().second > k) {
          queue.pop();
        } else {
          break;
        }
      }
      if (!queue.empty()) {
        max = std::max(point[0] + point[1] + queue.top().first, max);
      }
      queue.emplace(point[1] - point[0], point[0]);
    }
    return max;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}