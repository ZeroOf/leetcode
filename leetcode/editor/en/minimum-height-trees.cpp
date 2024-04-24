#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1) {
      return {0};
    }
    vector<vector<int>> node2Edges(n);
    vector<int> indegree(n, 0);

    for (auto &edge : edges) {
      node2Edges[edge[0]].push_back(edge[1]);
      indegree[edge[0]]++;
      node2Edges[edge[1]].push_back(edge[0]);
      indegree[edge[1]]++;
    }

    std::queue<int> leaves;

    for (int i = 0; i < n; ++i) {
      if (indegree[i] == 1) {
        leaves.push(i);
        indegree[i]--;
      }
    }

    vector<int> res;
    while (!leaves.empty()) {
      res.clear();
      auto numOfLeaves = leaves.size();
      for (int i = 0; i < numOfLeaves; ++i) {
        auto curr = leaves.front();
        leaves.pop();
        res.push_back(curr);
        for (auto vertex : node2Edges[curr]) {
          if (--indegree[vertex] == 1) {
            leaves.push(vertex);
          }
        }
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(minimum_height_trees, demo) {
  Solution solution;
  vector<vector<int>> input{
      {1, 0},
      {1, 2},
      {1, 3}
  };
  vector<int> expect{1};
  EXPECT_EQ(solution.findMinHeightTrees(4, input), expect);

  input = {
      {3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}
  };
  expect = {3, 4};

  EXPECT_EQ(solution.findMinHeightTrees(6, input), expect);
}