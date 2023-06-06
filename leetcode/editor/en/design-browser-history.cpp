#include <all.h>
namespace design_browser_history {

//leetcode submit region begin(Prohibit modification and deletion)
class BrowserHistory {
 public:
  BrowserHistory(string homepage)
      : history_{homepage}, cur_index_(0) {
  }

  void visit(string url) {
    history_.erase(history_.begin() + cur_index_ + 1, history_.end());
    history_.push_back(url);
    cur_index_ = history_.size() - 1;
  }

  string back(int steps) {
    cur_index_ -= steps;
    if (cur_index_ < 0) {
      cur_index_ = 0;
    }
    return history_[cur_index_];
  }

  string forward(int steps) {
    cur_index_ = cur_index_ + steps < history_.size() ? cur_index_ + steps : history_.size() - 1;
    return history_[cur_index_];
  }
 private:
  std::deque<string> history_;
  int cur_index_;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
//leetcode submit region end(Prohibit modification and deletion)

}