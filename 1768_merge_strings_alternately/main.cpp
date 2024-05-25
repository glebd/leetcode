#include <string>

#include <gtest/gtest.h>

// https://leetcode.com/problems/merge-strings-alternately/description/

class Solution
{
public:
  static std::string mergeAlternately(std::string word1, std::string word2)
  {
    return {};
  }
};

TEST(MergeStringsAlt, Test00)
{
  ASSERT_EQ(Solution::mergeAlternately("", ""), "");
}

TEST(MergeStringsAlt, Test01)
{
  ASSERT_EQ(Solution::mergeAlternately("abc", ""), "abc");
}

TEST(MergeStringsAlt, Test02)
{
  ASSERT_EQ(Solution::mergeAlternately("", "pqr"), "pqr");
}

TEST(MergeStringsAlt, Test1)
{
  ASSERT_EQ(Solution::mergeAlternately("abc", "pqr"), "apbqcr");
}

TEST(MergeStringsAlt, Test2)
{
  ASSERT_EQ(Solution::mergeAlternately("ab", "pqrs"), "apbqrs");
}

TEST(MergeStringsAlt, Test3)
{
  ASSERT_EQ(Solution::mergeAlternately("abcd", "pq"), "apbqcd");
}
