#include <string>
#include <vector>

#include <gtest/gtest.h>

// https://leetcode.com/explore/interview/card/leetcodes-interview-crash-course-data-structures-and-algorithms/703/arraystrings/4592/

class Solution
{
public:
  static void reverseString(std::vector<char>& s)
  {
  }
};

TEST(ReverseString, Test1)
{
  std::string const src{"hello"};
  std::string const exp{"olleh"};
  std::vector<char> input{std::begin(src), std::end(src)};
  std::vector<char> expected{std::begin(exp), std::end(exp)};
  Solution::reverseString(input);
  ASSERT_EQ(input, expected);
}

TEST(ReverseString, Test2)
{
  std::string const src{"Hannah"};
  std::string const exp{"hannaH"};
  std::vector<char> input{std::begin(src), std::end(src)};
  std::vector<char> expected{std::begin(exp), std::end(exp)};
  Solution::reverseString(input);
  ASSERT_EQ(input, expected);
}

TEST(ReverseString, Test3)
{
  std::string const src{"a"};
  std::string const exp{"a"};
  std::vector<char> input{std::begin(src), std::end(src)};
  std::vector<char> expected{std::begin(exp), std::end(exp)};
  Solution::reverseString(input);
  ASSERT_EQ(input, expected);
}
