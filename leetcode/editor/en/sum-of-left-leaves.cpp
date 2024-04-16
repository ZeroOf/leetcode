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

  int sumOfLeftLeaves(TreeNode *root) {
#if 0
    int sum = 0;
    sumOfLeftLeaves(root, sum, false);
    return sum;
#else
    std::queue<TreeNode *> leftQ;
    std::queue<TreeNode *> rightQ;
    int sum = 0;

    rightQ.push(root);
    while (!leftQ.empty() || !rightQ.empty()) {
      while (!leftQ.empty()) {
        auto pLeft = leftQ.front();
        if (nullptr == pLeft->left && nullptr == pLeft->right) {
          sum += pLeft->val;
        } else {
          if (pLeft->left) {
            leftQ.push(pLeft->left);
          }
          if (pLeft->right) {
            rightQ.push(pLeft->right);
          }
        }
        leftQ.pop();
      }
      while (!rightQ.empty()) {
        auto pRight = rightQ.front();
        if (nullptr != pRight->left) {
          leftQ.push(pRight->left);
        }
        if (nullptr != pRight->right) {
          rightQ.push(pRight->right);
        }
        rightQ.pop();
      }
    }
    return sum;
#endif
  }

 private:
#if 0
  void sumOfLeftLeaves(TreeNode *pNode, int &sum, bool isLeft) {
    auto pLeft = pNode->left;
    auto pRight = pNode->right;
    if (nullptr == pLeft && nullptr == pRight && isLeft) {
      sum += pNode->val;
    }

    if (nullptr != pLeft) {
      sumOfLeftLeaves(pLeft, sum, true);
    }

    if (nullptr != pRight) {
      sumOfLeftLeaves(pRight, sum, false);
    }
  }
#else

#endif
};
//leetcode submit region end(Prohibit modification and deletion)
