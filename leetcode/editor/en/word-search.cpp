#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:

  bool exist(vector<vector<char>> &board, string word) {
    vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
    int visitedIndex = 0;
    for (int row = 0; row < board.size(); ++row) {
      for (int column = 0; column < board[0].size(); ++column) {
        if (board[row][column] == word[0]) {
          visit[row][column] = true;
          if (exist(board, row, column, word, visitedIndex, visit)) {
            return true;
          }
          visit[row][column] = false;
        }
      }
    }
    return false;
  }

 private:
  bool exist(const vector<vector<char>> &board,
             int row,
             int column,
             const string &word,
             int visitedIndex,
             vector<vector<bool>> visit) {
    if (visitedIndex == word.size() - 1) {
      return true;
    }
    // up
    if (row > 0 && false == visit[row - 1][column] && board[row - 1][column] == word[visitedIndex + 1]) {
      visit[row - 1][column] = true;
      if (exist(board, row - 1, column, word, visitedIndex + 1, visit)) {
        return true;
      }
      visit[row - 1][column] = false;
    }

    // down
    if (row < board.size() - 1 && false == visit[row + 1][column] && board[row + 1][column] == word[visitedIndex + 1]) {
      visit[row + 1][column] = true;
      if (exist(board, row + 1, column, word, visitedIndex + 1, visit)) {
        return true;
      }
      visit[row + 1][column] = false;
    }
    // left
    if (column > 0 && false == visit[row][column - 1] && board[row][column - 1] == word[visitedIndex + 1]) {
      visit[row][column - 1] = true;
      if (exist(board, row, column - 1, word, visitedIndex + 1, visit)) {
        return true;
      }
      visit[row][column - 1] = false;
    }
    // right
    if (column < board[0].size() - 1 && false == visit[row][column + 1] &&
        board[row][column + 1] == word[visitedIndex + 1]) {
      visit[row][column + 1] = true;
      if (exist(board, row, column + 1, word, visitedIndex + 1, visit)) {
        return true;
      }
      visit[row][column + 1] = false;
    }
    return false;
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(word_search, demo) {
  Solution solution;
  vector<vector<char>> input{{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}};
  EXPECT_TRUE(solution.exist(input, "ABCCED"));
  EXPECT_TRUE(solution.exist(input, "SEE"));
  EXPECT_FALSE(solution.exist(input, "ABCB"));
}