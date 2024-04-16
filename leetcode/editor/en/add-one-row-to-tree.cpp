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
  TreeNode *addOneRow(TreeNode *root, int val, int depth) {
    auto sentry = std::make_unique<TreeNode>(0, root, nullptr);
    std::vector<TreeNode *> preLayer{sentry.get()};
    std::vector<TreeNode *> next;
    for (int curDepth = 1; curDepth < depth; ++curDepth) {
      for (auto pNode : preLayer) {
        if (pNode->left != nullptr) {
          next.push_back(pNode->left);
        }
        if (pNode->right != nullptr) {
          next.push_back(pNode->right);
        }
      }
      std::swap(preLayer, next);
      next.clear();
    }
    for (auto pNode : preLayer) {
      pNode->left = new TreeNode(val, pNode->left, nullptr);
      pNode->right = new TreeNode(val, nullptr, pNode->right);
    }
    return sentry->left;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(add_one_row_to_tree, demo) {
  Solution solution;
  auto pNode = new TreeNode(4, nullptr, nullptr);
  auto pLeft = new TreeNode(2, pNode, nullptr);
  auto pRight = new TreeNode(3, nullptr, nullptr);
  auto pRoot = new TreeNode(1, pLeft, pRight);
  solution.addOneRow(pRoot, 5, 4);
}