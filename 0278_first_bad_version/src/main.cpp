#include <functional>
#include <gtest/gtest.h>

// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.

//bool isBadVersion(int version)
//{
//    return false;
//}

class Solution
{
public:
    static int firstBadVersion(int n, const std::function<bool(int)>& isBadVersion)
    {
        int left = 1;
        int right = n;
        while (left < right)
        {
            int const mid = left + (right - left) / 2;
            if (isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

// Input: n = 5, bad = 4
// Output: 4
TEST(FirstBadVersion, Test1)
{
    ASSERT_EQ(Solution::firstBadVersion(5, [](int n) { return n >= 4; }), 4);
}

// Input: n = 1, bad = 1
// Output: 1
TEST(FirstBadVersion, Test2)
{
    ASSERT_EQ(Solution::firstBadVersion(1, [](int n) { return n >= 1; }), 1);
}

// Input: n = 2, bad = 2
// Output: 2
TEST(FirstBadVersion, Test3)
{
    ASSERT_EQ(Solution::firstBadVersion(2, [](int n) { return n >= 2; }), 2);
}

// Input: n = 2126753390, bad = 1702766719
// Output: 1702766719
TEST(FirstBadVersion, Test20)
{
    ASSERT_EQ(Solution::firstBadVersion(2126753390, [](int n) { return n >= 1702766719; }), 1702766719);
}
