#include <string>
#include <array>

#include <gtest/gtest.h>

// https://leetcode.com/problems/merge-strings-alternately/description/

class Solution
{
public:
  static std::string mergeAlternately(std::string word1, std::string word2)
  {
    std::string result;
    std::array word_ps{word1.c_str(), word2.c_str()};
    int index = 0;
    while (*word_ps[0] && *word_ps[1]) {
      const char*& word_p = word_ps[index];
      if (*word_p) {
        result += *word_p++;
        index = 1 - index;
      }
    }
    if (*word_ps[0])
      result += word_ps[0];
    else if (*word_ps[1])
      result += word_ps[1];
    return result;
  }
};

TEST(MergeStringsAlt, Test0)
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
