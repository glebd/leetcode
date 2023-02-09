#include <gtest/gtest.h>

#include <string>

// https://leetcode.com/problems/is-subsequence/?envType=study-plan&id=level-1
class Solution
{
public:
    static bool isSubsequence(const std::string& s, const std::string& t)
    {
        return false;
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
