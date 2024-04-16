#include <all.h>
#include <list>

namespace sum_root_to_leaf_numbers {

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
  int sumNumbers(TreeNode *root) {
    int sum = 0;
    sumNumbers(root, 0, sum);
    return sum;
  }

 private:

  void sumNumbers(TreeNode *pNode, int preSum, int &sum) {
    preSum *= 10;
    if (nullptr == pNode->left && nullptr == pNode->right) {
      sum += preSum + pNode->val;
      return;
    }
    preSum += pNode->val;
    if (nullptr != pNode->left) {
      sumNumbers(pNode->left, preSum, sum);
    }
    if (nullptr != pNode->right) {
      sumNumbers(pNode->right, preSum, sum);
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}