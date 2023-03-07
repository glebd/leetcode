#include <gtest/gtest.h>

#include <string>

// https://leetcode.com/problems/is-subsequence/?envType=study-plan&id=level-1
class Solution
{
public:
    static bool isSubsequence(const std::string& s, const std::string& t)
    {
        auto leftBound = s.length();
        auto rightBound = t.length();
        size_t left = 0;
        size_t right = 0;
        while (left < leftBound && right < rightBound)
        {
            if (s[left] == t[right])
            {
                ++left, ++right;
            }
            else
            {
                ++right;
            }
        }
        return left == leftBound;
    }
};

TEST(IsSubsequence, Test1)
{
    ASSERT_TRUE(Solution::isSubsequence("abc","ahbgdc"));
}

TEST(IsSubsequence, Test2)
{
    ASSERT_FALSE(Solution::isSubsequence("axc","ahbgdc"));
}

TEST(IsSubsequence, TestEmptyS)
{
    ASSERT_TRUE(Solution::isSubsequence("","ahbgdc"));
}

TEST(IsSubsequence, TestEmptyT)
{
    ASSERT_FALSE(Solution::isSubsequence("abc",""));
}

TEST(IsSubsequence, TestEmptyBoth)
{
    ASSERT_TRUE(Solution::isSubsequence("",""));
}

TEST(IsSubsequence, TestBC)
{
    ASSERT_FALSE(Solution::isSubsequence("b", "c"));
}
