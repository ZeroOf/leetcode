#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
 public:
  TreeNode *bstToGst(TreeNode *root) {
    int sum = 0;
    bstToGst(root, sum);
    return root;
  }

 private:
  void bstToGst(TreeNode *cur, int &preValue) {
    if (nullptr != cur->right) {
      bstToGst(cur->right, preValue);
    }
    preValue += cur->val;
    cur->val = preValue;
    if (nullptr == cur->left) {
      return;
    }
    bstToGst(cur->left, preValue);
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(binary_search_tree_to_greater_sum_tree, demo) {

  BinaryTree binaryTree("[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]");
  binaryTree.printBT();
  BinaryTree result("[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]");
  result.printBT();

  Solution solution;
  auto res = solution.bstToGst(binaryTree.getRoot());
  BinaryTree::printBT(res);
  EXPECT_EQ(*res, *result.getRoot());
}