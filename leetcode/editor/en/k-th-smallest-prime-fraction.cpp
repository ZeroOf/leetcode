#include <all.h>

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    return PriorityQueue(arr, k);
  }

 private:
  vector<int> PriorityQueue(vector<int> &arr, int k) {
    std::priority_queue<pair<double, pair<int, int>>> pq;

    for (int i = 0; i < arr.size(); ++i) {
      pq.push({-1.0 * arr[i] / arr.back(), {i, arr.size() - 1}});
    }

    while (--k > 0) {
      pair<int, int> cur = pq.top().second;
      pq.pop();
      cur.second--;
      pq.push({-1.0 * arr[cur.first] / arr[cur.second], {cur.first, cur.second}});
    }
    pair<int, int> result = pq.top().second;
    return {arr[result.first], arr[result.second]};
  }

  vector<int> BianrySearch(vector<int> &arr, int k) {
    double left = 0, right = 1;
    int n = arr.size();
    while (left < right) {
      double mid = (left + right) / 2;
      int smallerCount = 0, numeratorIdx = 0, denominatorIdx = 0;
      double maxFraction = 0;
      int j = 1;
      for (int i = 0; i < n - 1; i++) {
        while (j < n && arr[i] >= mid * arr[j]) {
          ++j;
        }

        smallerCount += n - j;

        if (j == n) {
          break;
        }

        double fraction = static_cast<double>(arr[i]) / arr[j];

        if (fraction > maxFraction) {
          numeratorIdx = i;
          denominatorIdx = j;
          maxFraction = fraction;
        }
      }
      if (smallerCount == k) {
        return {arr[numeratorIdx], arr[denominatorIdx]};
      } else if (smallerCount > k) {
        right = mid;
      } else {
        left = mid;
      }
    }
    return {};
  }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(k_th_smallest_prime_fraction, demo) {
  Solution solution;
  vector<int> arr = {1, 2, 3, 5};
  auto res = solution.kthSmallestPrimeFraction(arr, 3);
  vector<int> expect = vector<int>{2, 5};
  ASSERT_EQ(res, expect);
}