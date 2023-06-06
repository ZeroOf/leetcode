//You are given two integers n and k and two integer arrays speed and 
//efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and 
//efficiency[i] represent the speed and efficiency of the iᵗʰ engineer respectively. 
//
// Choose at most k different engineers out of the n engineers to form a team 
//with the maximum performance. 
//
// The performance of a team is the sum of their engineers' speeds multiplied 
//by the minimum efficiency among their engineers. 
//
// Return the maximum performance of this team. Since the answer can be a huge 
//number, return it modulo 10⁹ + 7. 
//
// 
// Example 1: 
//
// 
//Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
//Output: 60
//Explanation: 
//We have the maximum performance of the team by selecting engineer 2 (with 
//speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, 
//performance = (10 + 5) * min(4, 7) = 60.
// 
//
// Example 2: 
//
// 
//Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
//Output: 68
//Explanation:
//This is the same example as the first but k = 3. We can select engineer 1, 
//engineer 2 and engineer 5 to get the maximum performance of the team. That is, 
//performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
// 
//
// Example 3: 
//
// 
//Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
//Output: 72
// 
//
// 
// Constraints: 
//
// 
// 1 <= k <= n <= 10⁵ 
// speed.length == n 
// efficiency.length == n 
// 1 <= speed[i] <= 10⁵ 
// 1 <= efficiency[i] <= 10⁸ 
// 
//
// Related Topics Array Greedy Sorting Heap (Priority Queue) 👍 1678 👎 52

#include <all.h>
namespace maximum_performance_of_a_team {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
    vector<pair<int, int>> e2s;
    for (int i = 0; i < n; ++i) {
      e2s.push_back({efficiency[i], speed[i]});
    }
    std::sort(std::rbegin(e2s), std::rend(e2s));
    std::priority_queue<int, std::vector<int>, std::greater<int>> topS;
    long speedSum = 0;
    long max = 0;
    for (auto &[e, s] : e2s) {
      speedSum += s;
      topS.push(s);
      if (topS.size() > k) {
        speedSum -= topS.top();
        topS.pop();
      }
      max = std::max(max, speedSum * e);
    }
    return max % (int) (1e+9 + 7);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}