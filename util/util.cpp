
#include <sstream>
#include "util.h"
#include <queue>

bool ListNode::operator==(const ListNode &rhs) const {
  if (val != rhs.val) {
    return false;
  }
  auto pVisitOfThis = next;
  auto pVisitOfRhs = rhs.next;
  while (nullptr != pVisitOfRhs) {
    if (nullptr == pVisitOfRhs || pVisitOfRhs->val != pVisitOfThis->val) {
      return false;
    }
    pVisitOfRhs = pVisitOfRhs->next;
    pVisitOfThis = pVisitOfThis->next;
  }
  if (nullptr != pVisitOfRhs) {
    return false;
  }
  return true;
}

ListNode *CreateList(vector<int> nums) {
  auto pEnd = nums.rbegin();
  auto head = new ListNode(*pEnd);
  for (auto iEnd = pEnd + 1; iEnd != nums.rend(); ++iEnd) {
    head = new ListNode(*iEnd, head);
  }
  return head;
}

bool operator==(const TreeNode &lhs, const TreeNode &rhs) noexcept {
  if (lhs.val != rhs.val) {
    return false;
  }

  if (!lhs.left && !rhs.left || lhs.left && rhs.left && *lhs.left == *rhs.left) {
    return (!lhs.right && !rhs.right || lhs.right && rhs.right && *lhs.right == *rhs.right);
  }
  return false;
}

BinaryTree::BinaryTree(const string &data) {
  root_ = deserialize(data);
}

void BinaryTree::printInorder() const noexcept {
  vector<int> result;
  inorderTraversal(root_, result);
  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;
}

void BinaryTree::printBT() const noexcept {
  printBT("", root_, false);
}

TreeNode *BinaryTree::getRoot() const {
  return root_;
}

TreeNode *BinaryTree::deserialize(const string &data) {
  if (data.empty() || data == "[]") {
    return nullptr;
  }

  string content = data.substr(1, data.size() - 2); // Remove the brackets
  vector<string> nodes = split(content, ',');
  if (nodes.empty()) {
    return nullptr;
  }
  nodes_.reserve(nodes.size() + nodes.size());
  TreeNode *root = &nodes_.emplace_back(stoi(nodes[0]));
  queue<TreeNode *> q;
  q.push(root);
  int i = 1;
  while (!q.empty() && i < nodes.size()) {
    TreeNode *current = q.front();
    q.pop();
    if (nodes[i] != "null") {
      current->left = &nodes_.emplace_back(stoi(nodes[i]));
      q.push(current->left);
    }
    i++;
    if (i < nodes.size() && nodes[i] != "null") {
      current->right = &nodes_.emplace_back((stoi(nodes[i])));
      q.push(current->right);
    }
    i++;
  }
  return root;
}

vector<string> BinaryTree::split(const string &str, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(str);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

void BinaryTree::inorderTraversal(TreeNode *node, vector<int> &result) const noexcept {
  if (!node) {
    return;
  }
  inorderTraversal(node->left, result);
  result.push_back(node->val);
  inorderTraversal(node->right, result);
}

void BinaryTree::printBT(const std::string &prefix, const TreeNode *node, bool isLeft) noexcept {
  if (node != nullptr) {
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──");
    std::cout << node->val << std::endl;

    printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
    printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
  }
}

bool BinaryTree::operator==(const BinaryTree &rhs) const noexcept {
  return root_ == rhs.root_;
}

void BinaryTree::printBT(TreeNode *root) noexcept {
  printBT("", root, false);
}
