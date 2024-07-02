
#ifndef LEETCODE__UTIL_H_
#define LEETCODE__UTIL_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode *next) : val(x), next(next) {}

  bool operator==(const ListNode &rhs) const;
};

ListNode *CreateList(vector<int> nums);

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool operator==(const TreeNode &lhs, const TreeNode &rhs) noexcept;

class BinaryTree {
 public:
  BinaryTree(const string &data);

  void printInorder() const noexcept;

  void printBT() const noexcept;

  TreeNode *getRoot() const;

  static void printBT(TreeNode *root) noexcept;

  bool operator==(const BinaryTree &rhs) const noexcept;

 private:

  TreeNode *deserialize(const string &data);

  vector<string> split(const string &str, char delimiter);

  void inorderTraversal(TreeNode *node, vector<int> &result) const noexcept;

  static void printBT(const std::string &prefix, const TreeNode *node, bool isLeft) noexcept;

 private:
  TreeNode *root_;
  vector<TreeNode> nodes_;
};

#endif //LEETCODE__UTIL_H_
