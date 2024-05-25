#include <string>
#include <vector>

#include <gtest/gtest.h>

// https://leetcode.com/problems/merge-strings-alternately/description/

class Solution
{
public:
  static std::string mergeAlternately(std::string word1, std::string word2)
  {
    std::string result;
    std::vector<std::string*> word_ps{&word1, &word2};
    int index = 0;
    while (word1.length() && word2.length()) {
      std::string* word_p = word_ps[index];
      if (word_p->length()) {
        result += (*word_p)[0];
        *word_p = &(*word_p)[1];
        index = 1 - index;
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
