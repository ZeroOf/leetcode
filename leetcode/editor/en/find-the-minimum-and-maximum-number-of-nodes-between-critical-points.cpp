#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
 public:
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    ListNode *pre = head, *visit = head->next, *follow = visit->next;
    vector<int> res{INT_MAX, -1};
    int maxCount = -1, preIdx = -1;
    bool hasCritical = false;
    while (follow) {
      if (pre->val > visit->val && follow->val > visit->val
          || pre->val < visit->val && follow->val < visit->val) {
        if (hasCritical) {
          res[0] = min(res[0], maxCount + 1 - preIdx);
          res[1] = maxCount + 1;
        } else {
          hasCritical = true;
        }
        preIdx = maxCount + 1;
      }
      pre = visit;
      visit = follow;
      follow = visit->next;
      if (hasCritical) {
        maxCount++;
      }
    }
    if (res[1] == -1) {
      res[0] = -1;
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(find_the_minimum_and_maximum_number_of_nodes_between_critical_points, demo) {
  Solution solution;
  ListNode *head = CreateList({3, 1});
  vector<int> expect{-1, -1};
  EXPECT_EQ(solution.nodesBetweenCriticalPoints(head), expect);

  head = CreateList({5, 3, 1, 2, 5, 1, 2});
  expect = {1, 3};
  EXPECT_EQ(solution.nodesBetweenCriticalPoints(head), expect);

  head = CreateList({1, 3, 2, 2, 3, 2, 2, 2, 7});
  expect = {3, 3};
  EXPECT_EQ(solution.nodesBetweenCriticalPoints(head), expect);
}