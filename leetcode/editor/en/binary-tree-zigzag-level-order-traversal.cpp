#include <all.h>
namespace binary_tree_zigzag_level_order_traversal {
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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    if (nullptr == root) {
      return ret;
    }
    deque<TreeNode *> tmp{root};
    deque<TreeNode *> tmpNext{};
    bool left2right = true;
    while (!tmp.empty()) {
      vector<int> layer;
      if (left2right) {
        for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
          layer.push_back((*it)->val);
          if (nullptr != (*it)->left) {
            tmpNext.push_back((*it)->left);
          }
          if (nullptr != (*it)->right) {
            tmpNext.push_back((*it)->right);
          }
        }
      } else {
        for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
          layer.push_back((*it)->val);
          if (nullptr != (*it)->right) {
            tmpNext.push_back((*it)->right);
          }
          if (nullptr != (*it)->left) {
            tmpNext.push_back((*it)->left);
          }
        }
      }
      ret.push_back(layer);
      left2right = !left2right;
      tmp.clear();
      std::swap(tmp, tmpNext);
    }
    return ret;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}