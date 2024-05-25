#include <string>

#include <gtest/gtest.h>

// https://leetcode.com/problems/merge-strings-alternately/description/

class Solution
{
public:
  static std::string mergeAlternately(std::string word1, std::string word2)
  {
    std::string result;
    int index = 1;
    while (word1.length() && word2.length()) {
      if (index == 1 && word1.length()) {
        result += word1[0];
        word1 = &word1[1];
        index = 2;
      } else if (index == 2 && word2.length()) {
        result += word2[0];
        word2 = &word2[1];
        index = 1;
      }
    }
    if (word1.length())
      result += word1;
    else if (word2.length())
      result += word2;
    return result;
  }
};

TEST(MergeStringsAlt, Test00)
{
  ASSERT_EQ(Solution::mergeAlternately("a", "b"), "ab");
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
