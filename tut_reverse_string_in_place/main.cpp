#include <string>
#include <vector>

#include <gtest/gtest.h>

// https://leetcode.com/explore/interview/card/leetcodes-interview-crash-course-data-structures-and-algorithms/703/arraystrings/4592/

class Solution
{
public:
  void reverseString(std::vector<char>& s)
  {
    if (s.empty())
      return;
    size_t i1{0};
    size_t i2{s.size() - 1};
    while (i1 < i2)
    {
      std::swap(s[i1], s[i2]);
      i1++;
      i2--;
    }
  }
};

TEST(ReverseString, Test1)
{
  std::string const src{"hello"};
  std::string const exp{"olleh"};
  std::vector<char> input{std::begin(src), std::end(src)};
  std::vector<char> expected{std::begin(exp), std::end(exp)};
  Solution{}.reverseString(input);
  ASSERT_EQ(input, expected);
}

TEST(ReverseString, Test2)
{
  std::string const src{"Hannah"};
  std::string const exp{"hannaH"};
  std::vector<char> input{std::begin(src), std::end(src)};
  std::vector<char> expected{std::begin(exp), std::end(exp)};
  Solution{}.reverseString(input);
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
