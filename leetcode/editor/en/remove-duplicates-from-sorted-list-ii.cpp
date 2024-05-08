#include <all.h>

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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode pre(0, head);
    // left, mid, right
    ListNode *left = &pre, *right = head->next;
    bool hasSame = false;
    while (nullptr != left) {
      if (right == nullptr || right->val != left->next->val) {
        // left, left->value, left->value ... right
        if (hasSame) {
          left->next = right;
          right = nullptr == right ? nullptr : right->next;
          hasSame = false;
          // left, left->value, right
        } else {
          left = left->next;
          right = nullptr == right ? nullptr : right->next;
        }
      } else {
        hasSame = true;
        right = right->next;
      }
    }
    return pre.next;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(remove_duplicates_from_sorted_list_ii, demo) {
  Solution solution;

  ListNode *head = CreateList({1, 2, 3, 3, 4, 4, 5});
  head = solution.deleteDuplicates(head);

  ListNode *expect = CreateList({1, 2, 5});
  ASSERT_EQ(*expect, *head);
}