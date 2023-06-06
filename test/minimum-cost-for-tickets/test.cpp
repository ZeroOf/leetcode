#include <gtest/gtest.h>
#include <leetcode/editor/en/minimum-cost-for-tickets.cpp>

TEST(minimum_cost_for_tickets, test1) {
  using namespace minimum_cost_for_tickets;
  Solution s;
  vector<int> days = {1, 4, 6, 7, 8, 20};
  vector<int> costs = {2, 7, 15};
  EXPECT_EQ(s.mincostTickets(days, costs), 11);
}

TEST(minimum_cost_for_tickets, test2) {
  using namespace minimum_cost_for_tickets;
  Solution s;
  vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
  vector<int> costs = {2, 7, 15};
  EXPECT_EQ(s.mincostTickets(days, costs), 17);
}

TEST(minimum_cost_for_tickets, test3) {
  using namespace minimum_cost_for_tickets;
  Solution s;
  vector<int> days = {1, 4, 6, 7, 8, 20};
  vector<int> costs = {7, 2, 15};
  EXPECT_EQ(s.mincostTickets(days, costs), 6);
}