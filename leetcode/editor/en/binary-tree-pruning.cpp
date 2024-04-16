#include <all.h>

namespace binary_tree_pruning {

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
  TreeNode *pruneTree(TreeNode *root) {
    DeleteZeroTree(root);
    return root;
  }

 private:
  void DeleteZeroTree(TreeNode *&root) {
    if (root->left != nullptr) {
      DeleteZeroTree(root->left);
    }
    if (root->right != nullptr) {
      DeleteZeroTree(root->right);
    }
    if (root->left == nullptr && root->right == nullptr && root->val == 0) {
      root = nullptr;
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}