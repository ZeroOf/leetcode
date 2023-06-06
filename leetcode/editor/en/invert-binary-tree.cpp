//Given the root of a binary tree, invert the tree, and return its root. 
//
// 
// Example 1: 
// 
// 
//Input: root = [4,2,7,1,3,6,9]
//Output: [4,7,2,9,6,3,1]
// 
//
// Example 2: 
// 
// 
//Input: root = [2,1,3]
//Output: [2,3,1]
// 
//
// Example 3: 
//
// 
//Input: root = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [0, 100]. 
// -100 <= Node.val <= 100 
// 
//
// Related Topics Tree Depth-First Search Breadth-First Search Binary Tree 👍 11
//495 👎 163

#include <all.h>
namespace invert_binary_tree {
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
  TreeNode *invertTree(TreeNode *root) {
    std::deque<TreeNode *> pendingNodes;
    if (nullptr == root) {
      return root;
    }
    pendingNodes.push_back(root);
    while (!pendingNodes.empty()) {
      TreeNode *pCur = pendingNodes.front();
      if (nullptr != pCur->left) {
        pendingNodes.push_back(pCur->left);
      }
      if (nullptr != pCur->right) {
        pendingNodes.push_back(pCur->right);
      }
      std::swap(pCur->left, pCur->right);
      pendingNodes.pop_front();
    }
    return root;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}