#include <all.h>
#include <list>
namespace sum_root_to_leaf_numbers {

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
  int sumNumbers(TreeNode *root) {
    std::list<TreeNode *> numLine;
    int sum = 0;
    sumNumbers(root, numLine, sum);
    return sum;
  }
 private:
  void sumNumbers(TreeNode *root, std::list<TreeNode *> numLine, int &sum) {
    if (nullptr == root) {
      return;
    }
    numLine.push_back(root);
    if (nullptr == root->left && nullptr == root->right) {
      sum += list2Num(numLine);
      return;
    }
    if (nullptr != root->left) {
      sumNumbers(root->left, numLine, sum);
    }
    if (nullptr != root->right) {
      sumNumbers(root->right, numLine, sum);
    }
  }
  int list2Num(std::list<TreeNode *> numLine) {
    int ret = 0, digit = 1;
    std::reverse(numLine.begin(), numLine.end());
    ret += (*numLine.begin())->val;
    numLine.pop_front();
    for (auto pNode : numLine) {
      digit *= 10;
      ret += pNode->val * digit;
    }
    return ret;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}