#include <gtest/gtest.h>
#include <leetcode/editor/en/sum-root-to-leaf-numbers.cpp>

class SRTLNTest : public ::testing::Test {
 public:
  sum_root_to_leaf_numbers::Solution solution_;
};

void AddNode(sum_root_to_leaf_numbers::TreeNode *&root, int val) {
  root = new sum_root_to_leaf_numbers::TreeNode(val);
}

TEST_F(SRTLNTest, demo) {
  sum_root_to_leaf_numbers::TreeNode *root = nullptr;
  AddNode(root, 2);
  AddNode(root->left, 1);
  AddNode(root->left->left, 4);
  AddNode(root->left->left->left, 7);
  AddNode(root->left->left->left->left, 4);
  AddNode(root->left->left->left->left->left, 8);
  AddNode(root->left->left->left->left->left->left, 3);
  AddNode(root->left->left->left->left->left->left->left, 6);
  AddNode(root->left->left->left->left->left->left->left->left, 4);
  AddNode(root->left->left->left->left->left->left->left->left->left, 7);

  EXPECT_EQ(solution_.sumNumbers(root), 2147483647);
}