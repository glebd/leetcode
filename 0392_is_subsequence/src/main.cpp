#include <gtest/gtest.h>

#include <string>

// https://leetcode.com/problems/is-subsequence/?envType=study-plan&id=level-1
class Solution
{
public:
    static bool isSubsequence(const std::string& s, const std::string& t)
    {
        int last_t_index = -1;
        for (size_t i = 0; i < s.length(); ++i)
        {
            bool found = false;
            for (int j = last_t_index + 1; j < static_cast<int>(t.length()); ++j)
            {
                if (t[j] == s[i])
                {
                    last_t_index = j;
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
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
