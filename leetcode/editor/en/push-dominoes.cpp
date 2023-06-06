//There are n dominoes in a line, and we place each domino vertically upright. 
//In the beginning, we simultaneously push some of the dominoes either to the left 
//or to the right. 
//
// After each second, each domino that is falling to the left pushes the 
//adjacent domino on the left. Similarly, the dominoes falling to the right push their 
//adjacent dominoes standing on the right. 
//
// When a vertical domino has dominoes falling on it from both sides, it stays 
//still due to the balance of the forces. 
//
// For the purposes of this question, we will consider that a falling domino 
//expends no additional force to a falling or already fallen domino. 
//
// You are given a string dominoes representing the initial state where: 
//
// 
// dominoes[i] = 'L', if the iᵗʰ domino has been pushed to the left, 
// dominoes[i] = 'R', if the iᵗʰ domino has been pushed to the right, and 
// dominoes[i] = '.', if the iᵗʰ domino has not been pushed. 
// 
//
// Return a string representing the final state. 
//
// 
// Example 1: 
//
// 
//Input: dominoes = "RR.L"
//Output: "RR.L"
//Explanation: The first domino expends no additional force on the second 
//domino.
// 
//
// Example 2: 
// 
// 
//Input: dominoes = ".L.R...LR..L.."
//Output: "LL.RR.LLRRLL.."
// 
//
// 
// Constraints: 
//
// 
// n == dominoes.length 
// 1 <= n <= 10⁵ 
// dominoes[i] is either 'L', 'R', or '.'. 
// 
//
// Related Topics Two Pointers String Dynamic Programming 👍 2514 👎 159

#include <all.h>
namespace push_dominoes {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  string pushDominoes(string dominoes) {
    size_t begin = 0;
    while (begin < dominoes.size()) {
      switch (dominoes[begin]) {
        case '.': {
          auto end = dominoes.find_first_not_of('.', begin);
          if (end == string::npos) {
            return dominoes;
          }
          if (dominoes[end] == 'L') {
            for (size_t i = begin; i <= end; ++i) {
              dominoes[i] = 'L';
            }
            begin = end + 1;
          } else {
            begin = end;
          }
          break;
        }
        case 'L': {
          begin++;
          break;
        }
        case 'R': {
//          auto end = dominoes.find('L', begin);
          if (begin == dominoes.size() - 1) {
            return dominoes;
          }
          auto end = dominoes.find_first_not_of('.', begin + 1);
          if (end == string::npos) {
            for (int i = begin + 1; i < dominoes.size(); ++i) {
              dominoes[i] = 'R';
            }
            return dominoes;
          }
          switch (dominoes[end]) {
            case 'R': {
              for (int i = begin + 1; i < end; ++i) {
                dominoes[i] = 'R';
              }
              begin = end;
              break;
            }
            case 'L': {
              while (begin < end) {
                dominoes[begin++] = 'R';
                dominoes[end--] = 'L';
              }
              begin = end + 1;
              break;
            }
          }
          break;
        }
      }
    }
    return dominoes;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}