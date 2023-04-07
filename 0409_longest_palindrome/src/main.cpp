#include <gtest/gtest.h>

#include <string>
#include <unordered_map>

class Solution
{
public:
    static int longestPalindrome(std::string s)
    {
        std::unordered_map<char, int> freq;
        // build character frequency map
        for (const char ch: s)
        {
            if (freq.find(ch) == freq.end())
            {
                freq.insert({ch, 1});
            }
            else
            {
                ++freq[ch];
            }
        }
        int max_len = 0;
        // check all character frequencies
        bool middle = false;
        for (const auto& [ch, n]: freq)
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
