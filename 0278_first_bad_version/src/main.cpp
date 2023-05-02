#include <gtest/gtest.h>

// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
bool isBadVersion(int version)
{
    return false;
}

class Solution
{
public:
    static int firstBadVersion(int n)
    {
        return 0;
    }
};

// Input: n = 5, bad = 4
// Output: 4
TEST(FirstBadVersion, Test1)
{
    ASSERT_EQ(Solution::firstBadVersion(5), 4);
}

// Input: n = 1, bad = 1
// Output: 1
TEST(FirstBadVersion, Test2)
{
    ASSERT_EQ(Solution::firstBadVersion(1), 1);
}
