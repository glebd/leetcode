#include <gtest/gtest.h>

#include <string>

class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        return false;
    }
};

TEST(RansomNote, Test1)
{
    Solution solution;
    ASSERT_FALSE(solution.canConstruct("a", "b"));
}

TEST(RansomNote, Test2)
{
    Solution solution;
    ASSERT_FALSE(solution.canConstruct("aa", "ab"));
}

TEST(RansomNote, Test3)
{
    Solution solution;
    ASSERT_TRUE(solution.canConstruct("aa", "aab"));
}
