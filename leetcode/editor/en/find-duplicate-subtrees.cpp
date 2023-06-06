#include <all.h>
namespace find_duplicate_subtrees {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
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
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {

  }
  bool isSame(TreeNode *lhs, TreeNode *rhs) {
    if (lhs == nullptr && rhs == nullptr) {
      return true;
    }
    if (lhs == nullptr || rhs == nullptr) {
      return false;
    }
    return lhs->val == rhs->val && isSame(lhs->left, rhs->left) && isSame(lhs->right, rhs->right);
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}