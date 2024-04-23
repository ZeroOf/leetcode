#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 public:
  void smallestFromLeaf(TreeNode *pNode, std::deque<int> visited, std::deque<int> &min) {
    visited.push_front(pNode->val);
    if (pNode->left == nullptr && pNode->right == nullptr) {
      min = min > visited ? visited : min;
      return;
    }

    if (nullptr != pNode->left) {
      smallestFromLeaf(pNode->left, visited, min);
    }
    if (nullptr != pNode->right) {
      smallestFromLeaf(pNode->right, visited, min);
    }
  }

  string smallestFromLeaf(TreeNode *root) {
    std::deque<int> min(1000, 26);
    std::deque<int> visited;
    smallestFromLeaf(root, visited, min);
    std::string ret;
    for (auto i : min) {
      ret.push_back('a' + i);
    }
    return ret;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
