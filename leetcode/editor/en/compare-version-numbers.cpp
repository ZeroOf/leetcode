#include <all.h>


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:

  int compareVersion(string version1, string version2) {
    int index1 = 0, index2 = 0;
    while (index1 < version1.size() || index2 < version2.size()) {
      string num1 = findNum(version1, index1);
      string num2 = findNum(version2, index2);
      if (num1.size() != num2.size()) {
        return num1.size() > num2.size() ? 1 : -1;
      }
      if (num1 > num2) return 1;
      if (num1 < num2) return -1;
      if (index1 < version1.size() && version1[index1] == '.') index1++;
      if (index2 < version2.size() && version2[index2] == '.') index2++;
    }
    return 0;
  }

 private:
  string findNum(const std::string &version, int &index) {
    while (index < version.size() && version[index] == '0') index++;
    int start = index;
    while (index < version.size() && version[index] != '.') index++;
    return version.substr(start, index - start);
  }

};
//leetcode submit region end(Prohibit modification and deletion)


TEST(compare_version_numbers, demo) {
  Solution solution;
  EXPECT_EQ(solution.compareVersion("1.0", "1"), 0);
  EXPECT_EQ(solution.compareVersion("1.0.1", "1"), 1);
  EXPECT_EQ(solution.compareVersion("0.1", "1"), -1);
  EXPECT_EQ(solution.compareVersion("1.0.1", "1.0"), 1);
  EXPECT_EQ(solution.compareVersion("1.1", "1.10"), -1);
  EXPECT_EQ(solution.compareVersion("1.2147483647", "1.2147483647"), 0);
  EXPECT_EQ(solution.compareVersion("1.2147483648", "1.2147483647"), 1);
  EXPECT_EQ(solution.compareVersion("1.2147483647", "1.2147483648"), -1);
  EXPECT_EQ(solution.compareVersion("1.2", "1.10"), -1);
}