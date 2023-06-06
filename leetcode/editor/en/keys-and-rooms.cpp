//There are n rooms labeled from 0 to n - 1 and all the rooms are locked except 
//for room 0. Your goal is to visit all the rooms. However, you cannot enter a 
//locked room without having its key. 
//
// When you visit a room, you may find a set of distinct keys in it. Each key 
//has a number on it, denoting which room it unlocks, and you can take all of them 
//with you to unlock the other rooms. 
//
// Given an array rooms where rooms[i] is the set of keys that you can obtain 
//if you visited room i, return true if you can visit all the rooms, or false 
//otherwise. 
//
// 
// Example 1: 
//
// 
//Input: rooms = [[1],[2],[3],[]]
//Output: true
//Explanation: 
//We visit room 0 and pick up key 1.
//We then visit room 1 and pick up key 2.
//We then visit room 2 and pick up key 3.
//We then visit room 3.
//Since we were able to visit every room, we return true.
// 
//
// Example 2: 
//
// 
//Input: rooms = [[1,3],[3,0,1],[2],[0]]
//Output: false
//Explanation: We can not enter room number 2 since the only key that unlocks 
//it is in that room.
// 
//
// 
// Constraints: 
//
// 
// n == rooms.length 
// 2 <= n <= 1000 
// 0 <= rooms[i].length <= 1000 
// 1 <= sum(rooms[i].length) <= 3000 
// 0 <= rooms[i][j] < n 
// All the values of rooms[i] are unique. 
// 
//
// Related Topics Depth-First Search Breadth-First Search Graph 👍 4574 👎 219

#include <all.h>
#include <bitset>
namespace keys_and_rooms {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    std::vector<bool> visit(rooms.size(), false);
    if (rooms[0].size() == 0) {
      return false;
    }
    deque<int> visiting{0};
    while (!visiting.empty()) {
      for (auto roomNum : rooms[visiting.front()]) {
        if (!visit[roomNum]) {
          visit[roomNum] = true;
          visiting.push_back(roomNum);
        }
      }
      visit[visiting.front()] = true;
      visiting.pop_front();
    }
    for (auto item : visit) {
      if (!item) {
        return false;
      }
    }
    return true;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}