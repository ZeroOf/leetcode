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
  ListNode *removeZeroSumSublists(ListNode *head) {
//    return BruteForce(head);
    return MapCount(head);
  }

  ListNode *BruteForce(ListNode *head) {
    auto pHead = new ListNode(0, head);
    auto pEnd = head->next;
    if (pEnd == nullptr && head->val == 0) {
      return nullptr;
    }
    // check if [head, pEnd] has 0 sum array
    while (pEnd != nullptr) {
      // [pStart, pEnd]
      for (auto pStart = pHead; pStart != pEnd->next; pStart = pStart->next) {
        CutDown0(pEnd, pStart);
      }
      pEnd = pEnd->next;
    }
    return pHead->next;
  }

  // cut all sub list which sum is 0 in [pStart->net, pEnd]
  void CutDown0(const ListNode *pEnd, ListNode *pStart) const {
    int sum = 0;
    for (auto pCur = pStart->next; pCur != pEnd->next; pCur = pCur->next) {
      sum += pCur->val;
      if (0 == sum) {
        pStart->next = pCur->next;
      }
    }
  }

  ListNode *MapCount(ListNode *head) {
    auto front = new ListNode(0, head);
    auto current = front;
    int prefixSum = 0;
    unordered_map < int, ListNode * > prefixSumToNode;

    while (current != nullptr) {
      prefixSum += current->val;
      prefixSumToNode[prefixSum] = current;
      current = current->next;
    }

    prefixSum = 0;
    current = front;

    while (current != nullptr) {
      prefixSum += current->val;
      current->next = prefixSumToNode[prefixSum]->next;
      current = current->next;
    }
    return front->next;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(remove_zero_sum_consecutive_nodes_from_linked_list, demo) {
  Solution solution;

  auto pHead = CreateList({1, 2, -3, 3, 1});
  auto pExpect = CreateList({3, 1});
  auto pRet = solution.removeZeroSumSublists(pHead);
  EXPECT_EQ(*pRet, *pExpect);
  while (pRet != nullptr) {
    std::cout << pRet->val << std::endl;
    pRet = pRet->next;
  }
}

TEST(remove_zero_sum_consecutive_nodes_from_linked_list, demo2) {
  Solution solution;

  auto pHead = CreateList({1, 2, 3, -3, 4});
  auto pExpect = CreateList({1, 2, 4});
  auto pRet = solution.removeZeroSumSublists(pHead);
  EXPECT_EQ(*pRet, *pExpect);
  while (pRet != nullptr) {
    std::cout << pRet->val << std::endl;
    pRet = pRet->next;
  }
}

TEST(remove_zero_sum_consecutive_nodes_from_linked_list, demo3) {
  Solution solution;

  auto pHead = CreateList({1, 2, 3, -3, -2});
  auto pExpect = CreateList({1});
  auto pRet = solution.removeZeroSumSublists(pHead);
  EXPECT_EQ(*pRet, *pExpect);
  while (pRet != nullptr) {
    std::cout << pRet->val << std::endl;
    pRet = pRet->next;
  }
}
