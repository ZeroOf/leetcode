#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<vector<int>> findFarmland(vector<vector<int>> &land) {
    return Greedy(land);
  }

 private:
  auto DFSFind(vector<vector<int>> &land) -> vector<vector<int>> {
    vector<vector<bool>> visit(land.size(), vector<bool>(land[0].size(), false));
    vector<vector<int>> ret;
    for (int i = 0; i < land.size(); ++i) {
      for (int j = 0; j < land[0].size(); ++j) {
        if (!visit[i][j] && land[i][j]) {
          int row = i;
          int col = j;
          DFS(land, visit, i, j, row, col);
          ret.push_back({i, j, row, col});
        }
      }
    }
    return ret;
  }

  static constexpr int dirs[4][2] = {
      {-1, 0},
      {0, -1},
      {1, 0},
      {0, 1}
  };

  bool InRange(int row2, int col2, int maxRow, int maxColumn) const {
    return row2 >= 0 && row2 < maxRow && col2 >= 0 && col2 < maxColumn;
  }

  void DFS(const vector<vector<int>> &land, vector<vector<bool>> &visit, int x, int y, int &row, int &col) {
    visit[x][y] = true;
    row = max(x, row);
    col = max(y, col);

    for (auto dir : dirs) {
      auto row2 = x + dir[0];
      auto col2 = y + dir[1];
      if (InRange(row2, col2, land.size(), land[0].size()) && land[row2][col2] && !visit[row2][col2]) {
        DFS(land, visit, row2, col2, row, col);
      }
    }
  }

 private:
  std::pair<int, int> BFS(vector<vector<int>> &land,
                          vector<vector<bool>> &visit,
                          queue<std::pair<int, int>> pendingVisit) {
    std::pair<int, int> curr;
    while (!pendingVisit.empty()) {
      curr = pendingVisit.front();
      pendingVisit.pop();
      visit[curr.first][curr.second] = true;

      for (auto &dir : dirs) {
        auto row = curr.first + dir[0];
        auto col = curr.second + dir[1];
        if (InRange(row, col, land.size(), land[0].size()) && land[row][col] && !visit[row][col]) {
          pendingVisit.push({row, col});
        }
      }
    }
    return curr;
  }

  vector<vector<int>> BFSFind(vector<vector<int>> &land) {
    vector<vector<int>> ret;
    vector<vector<bool>> visit(land.size(), vector<bool>(land[0].size(), false));
    for (int row = 0; row < land.size(); ++row) {
      for (int col = 0; col < land[0].size(); ++col) {
        if (land[row][col] && !visit[row][col]) {
          std::queue<std::pair<int, int>> q;
          q.push({row, col});
          std::pair<int, int> rightBottom = BFS(land, visit, q);
          ret.push_back({row, col, rightBottom.first, rightBottom.second});
        }
      }
    }
    return ret;
  }

 private:
  vector<vector<int>> Greedy(vector<vector<int>> &land) {
    int M = land.size(), N = land[0].size();
    vector<vector<int>> res;

    for (int row1 = 0; row1 < M; ++row1) {
      for (int col1 = 0; col1 < N; ++col1) {
        if (land[row1][col1]) {
          int x = row1;
          int y = col1;
          for (x = row1; x < M && land[x][col1]; x++) {
            for (y = col1; y < N && land[x][y]; y++) {
              land[x][y] = 0;
            }
          }
          res.push_back({row1, col1, x - 1, y - 1});
        }
      }
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(find_all_groups_of_farmland, demo) {
  Solution solution;

  vector<vector<int>> input{
      {1, 0, 0,},
      {0, 1, 1,},
      {0, 1, 1,}
  };
  vector<vector<int>> out{
      {0, 0, 0, 0},
      {1, 1, 2, 2}
  };
  EXPECT_EQ(solution.findFarmland(input), out);
}