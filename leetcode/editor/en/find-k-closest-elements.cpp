//Given a sorted integer array arr, two integers k and x, return the k closest 
//integers to x in the array. The result should also be sorted in ascending order. 
//
//
// An integer a is closer to x than an integer b if: 
//
// 
// |a - x| < |b - x|, or 
// |a - x| == |b - x| and a < b 
// 
//
// 
// Example 1: 
// Input: arr = [1,2,3,4,5], k = 4, x = 3
//Output: [1,2,3,4]
// 
// Example 2: 
// Input: arr = [1,2,3,4,5], k = 4, x = -1
//Output: [1,2,3,4]
// 
// 
// Constraints: 
//
// 
// 1 <= k <= arr.length 
// 1 <= arr.length <= 10⁴ 
// arr is sorted in ascending order. 
// -10⁴ <= arr[i], x <= 10⁴ 
// 
//
// Related Topics Array Two Pointers Binary Search Sorting Heap (Priority Queue)
// 👍 5692 👎 487

#include <all.h>
namespace find_k_closest_elements {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int head = 0, tail = arr.size() - 1;
    while (head < tail) {
      int mid = (head + tail) / 2;
      if (arr[mid] == x) {
        head = mid;
        tail = mid;
        break;
      }

      if (arr[mid] < x) {
        if (mid < arr.size() - 1) {
          head = mid + 1;
          continue;
        }
        head = tail;
        break;
      }

      if (arr[mid] > x) {
        tail = mid;
        continue;
      }
    }
    if (arr[head] >= x && head > 0 || head == arr.size() - 1 && arr.size() != 1) {
      --head;
    } else if (tail < arr.size() - 1) {
      ++tail;
    }
    vector<int> ret;
    for (int i = 0; i < k; ++i) {
      if (abs(arr[head] - x) <= abs(arr[tail] - x)) {
        if (head > 0) {
          ret.push_back(arr[head--]);
        } else {
          ret.push_back(arr[head]);
          if (head == tail) {
            tail++;
          }
          for (int j = 0; j < k - i - 1; ++j) {
            ret.push_back(arr[tail++]);
          }
          break;
        }
      } else {
        if (tail < arr.size() - 1) {
          ret.push_back(arr[tail++]);
        } else {
          ret.push_back(arr[tail]);
          if (head == tail) {
            head--;
          }
          for (int j = 0; j < k - i - 1; ++j) {
            ret.push_back(arr[head--]);
          }
          break;
        }
      }
    }
    std::sort(ret.begin(), ret.end());
    return ret;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}