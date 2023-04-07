#include <gtest/gtest.h>

#include <string>
#include <array>

class Solution
{
public:
    static int longestPalindrome(std::string const& s)
    {
        std::array<int, 128> freq = {};
        // build character frequency map
        for (char const ch: s)
        {
            ++freq[ch];
        }
        int max_len = 0;
        // check all character frequencies
        bool middle = false;
        for (int const n: freq)
        {
            // get no. of chars that can be paired
            max_len += (n / 2) * 2;
            if (!middle && max_len % 2 == 0 && n % 2 != 0)
            {
                ++max_len;
                middle = true;
            }
        }
        return max_len;
    }
};

TEST(LongestPalindrome, Test1)
{
    // dccaccd
    ASSERT_EQ(Solution::longestPalindrome("abccccdd"), 7);
}

TEST(LongestPalindrome, Test2)
{
    ASSERT_EQ(Solution::longestPalindrome("a"), 1);
}

TEST(LongestPalindrome, TestEmpty)
{
    ASSERT_EQ(Solution::longestPalindrome(""), 0);
}
