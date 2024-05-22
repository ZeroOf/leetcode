#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int largestRectangleArea(vector<int> &heights) {
    std::stack<int> low2high;
    int maxArea = 0;
    for (int i = 0; i < heights.size(); ++i) {
      // while need to stack equal value
      if (low2high.empty() || heights[low2high.top()] <= heights[i]) {
        low2high.push(i);
      } else {
        while (!low2high.empty() && heights[low2high.top()] > heights[i]) {
          auto highest = heights[low2high.top()];
          low2high.pop();
          auto pre = low2high.empty() ? -1 : low2high.top();
          maxArea = std::max(maxArea, highest * (i - pre - 1));
        }
        low2high.push(i);
      }
    }

    // calculate all areas
    while (!low2high.empty()) {
      auto top_fo_stack = low2high.top();
      low2high.pop();
      auto pre = low2high.empty() ? -1 : low2high.top();
      int area = (heights[top_fo_stack] * (heights.size() - 1 - pre));
      maxArea = std::max(maxArea, area);
    }
    return maxArea;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(largest_rectangle_in_histogram, demo) {
  Solution solution;
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  auto res = solution.largestRectangleArea(heights);
  EXPECT_EQ(10, res);
}