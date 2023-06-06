#include <gtest/gtest.h>
#include <leetcode/editor/en/text-justification.cpp>

class TextJ : public ::testing::Test {
 public:
  void SetUp() override {
  }
 protected:
  text_justification::Solution solution_;
};

TEST_F(TextJ, demo) {
  vector<string> input{"This", "is", "an", "example", "of", "text", "justification."};
  vector<string> output{"This    is    an", "example  of text", "justification.  "};
  EXPECT_EQ(solution_.fullJustify(input, 16), output);
}