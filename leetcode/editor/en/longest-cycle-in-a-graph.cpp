#include <all.h>
#include <bitset>
namespace longest_cycle_in_a_graph {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int longestCycle(vector<int> &edges) {
    int res = -1;
    std::bitset<100000> visited;
    for (int i = 0; i < edges.size(); ++i) {
      if (-1 == edges[i] || visited[i]) {
        continue;
      }
      vector<int> graph{edges[i]};
      res = std::max(res, dfs(edges, graph, i, visited));
    }
    return res;
  }
  int dfs(const vector<int> &edges, vector<int> &graph, int i, bitset<100000> &visited) {
    while (graph.back() != i) {
      if (-1 == edges[graph.back()]) {
        return -1;
      }
      if (visited[edges[graph.back()]]) {
        auto it = std::find(graph.begin(), graph.end(), edges[graph.back()]);
        if (it == graph.end()) {
          return -1;
        }
        return graph.end() - it;
      }
      visited[edges[graph.back()]] = true;
      graph.push_back(edges[graph.back()]);
    }
    return graph.size();
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}