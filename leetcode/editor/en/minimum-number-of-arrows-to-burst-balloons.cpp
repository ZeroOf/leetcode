//There are some spherical balloons taped onto a flat wall that represents the 
//XY-plane. The balloons are represented as a 2D integer array points where points[
//i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches 
//between xstart and xend. You do not know the exact y-coordinates of the balloons. 
//
// Arrows can be shot up directly vertically (in the positive y-direction) from 
//different points along the x-axis. A balloon with xstart and xend is burst by 
//an arrow shot at x if xstart <= x <= xend. There is no limit to the number of 
//arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any 
//balloons in its path. 
//
// Given the array points, return the minimum number of arrows that must be 
//shot to burst all balloons. 
//
// 
// Example 1: 
//
// 
//Input: points = []
//Output: 2
//Explanation: The balloons can be burst by 2 arrows:
//- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
//- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
// 
//
// Example 2: 
//
// 
//Input: points = [[1,2],[3,4],[5,6],[7,8]]
//Output: 4
//Explanation: One arrow needs to be shot for each balloon for a total of 4 
//arrows.
// 
//
// Example 3: 
//
// 
//Input: points = [[1,2],[2,3],[3,4],[4,5]]
//Output: 2
//Explanation: The balloons can be burst by 2 arrows:
//- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
//- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
// 
//
// 
// Constraints: 
//
// 
// 1 <= points.length <= 10⁵ 
// points[i].length == 2 
// -2³¹ <= xstart < xend <= 2³¹ - 1 
// 
//
// Related Topics Array Greedy Sorting 👍 5151 👎 142

#include <all.h>
namespace minimum_number_of_arrows_to_burst_balloons {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>> &points) {
    std::sort(points.begin(), points.end());
    int startIndex = 0;
    int result = 1;
    std::pair<int, int> scope{points[0][0], points[0][1]};
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] <= scope.second) {
        scope.first = points[i][0];
        scope.second = points[i][1] < scope.second ? points[i][1] : scope.second;
        continue;
      }
      scope.first = points[i][0];
      scope.second = points[i][1];
      ++result;
    }
    return result;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}