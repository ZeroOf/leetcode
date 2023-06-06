#include <gtest/gtest.h>
#include <leetcode/editor/en/string-compression-ii.cpp>

class SCIITest : public ::testing::Test {
 public:
  string_compression_ii::Solution solution_;
};

TEST_F(SCIITest, RunLengthDemo){
  string input("aaabccc");
  solution_.runLength(input);
  EXPECT_EQ(input, "a3bc3");
}