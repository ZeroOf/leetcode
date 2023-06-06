#include <all.h>
namespace merge_k_sorted_lists {

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    auto compare = [](ListNode *lhs, ListNode *rhs) {
      return lhs->val > rhs->val;
    };
    priority_queue<ListNode *, deque<ListNode *>, decltype(compare)> pq(compare);
    for (auto node : lists) {
      if (nullptr != node) {
        pq.push(node);
      }
    }

    if (pq.empty()) {
      return nullptr;
    }

    ListNode *head = pq.top();
    ListNode *cur = head;
    pq.pop();
    if (cur->next != nullptr) {
      pq.push(cur->next);
    }

    while (!pq.empty()) {
      cur->next = pq.top();
      cur = cur->next;
      pq.pop();
      if (cur->next != nullptr) {
        pq.push(cur->next);
      }
    }
    cur->next = nullptr;
    return head;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}