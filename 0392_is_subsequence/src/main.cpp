#include <gtest/gtest.h>

#include <string>

// https://leetcode.com/problems/is-subsequence/?envType=study-plan&id=level-1
class Solution
{
public:
    static bool isSubsequence(const std::string& s, const std::string& t)
    {
        return isSubsequenceRec(s, 0, t, 0);
    }

    static bool isSubsequenceRec(const std::string& s, int index_s, const std::string& t, int index_t)
    {
        if (index_s > static_cast<int>(s.length()) - 1)
            return true;
        if (index_t > static_cast<int>(t.length()) - 1)
            return false;
        if (s[index_s] == t[index_t])
            return isSubsequenceRec(s, index_s + 1, t, index_t + 1);
        return isSubsequenceRec(s, index_s, t, index_t + 1);
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
