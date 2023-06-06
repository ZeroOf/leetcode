#include <all.h>
namespace number_of_provinces {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int num = 0;
    int n = isConnected.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (visited[i]) {
        continue;
      }
      bfs(isConnected, visited, i);
      num++;
    }
    return num;
  }
  void bfs(vector<vector<int>> &isConnected, vector<bool> &visited, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty()) {
      node = q.front();
      q.pop();
      for (int i = 0; i < isConnected.size(); ++i) {
        if (isConnected[node][i] && !visited[i]) {
          q.push(i);
          visited[i] = true;
        }
      }
    }
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}