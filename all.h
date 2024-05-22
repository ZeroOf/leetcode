//
// Created by Will Lee on 2022/1/6.
//

#ifndef LEETCODE__ALL_H_
#define LEETCODE__ALL_H_

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <gtest/gtest.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}

  bool operator==(const ListNode &rhs) const {
    if (val != rhs.val) {
      return false;
    }
    auto pVisitOfThis = next;
    auto pVisitOfRhs = rhs.next;
    while (nullptr != pVisitOfRhs) {
      if (nullptr == pVisitOfRhs || pVisitOfRhs->val != pVisitOfThis->val) {
        return false;
      }
      pVisitOfRhs = pVisitOfRhs->next;
      pVisitOfThis = pVisitOfThis->next;
    }
    if (nullptr != pVisitOfRhs) {
      return false;
    }
    return true;
  }
};

inline ListNode *CreateList(vector<int> nums) {
  auto pEnd = nums.rbegin();
  auto head = new ListNode(*pEnd);
  for (auto iEnd = pEnd + 1; iEnd != nums.rend(); ++iEnd) {
    head = new ListNode(*iEnd, head);
  }
  return head;
}

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class BinaryTreeConstructor {
 public:
  BinaryTreeConstructor() {}

  virtual ~BinaryTreeConstructor() {
  }

 private:
  vector<TreeNode> nodes_;
};

#endif //LEETCODE__ALL_H_
