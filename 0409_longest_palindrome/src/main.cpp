#include <gtest/gtest.h>

#include <string>
#include <map>

class Solution
{
public:
    static int longestPalindrome(std::string s)
    {
        std::map<char, int> freq;
        // build character frequency map
        for (const char ch : s)
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
        int middle = 0;
        // check all character frequencies
        for (const auto& [ch, n] : freq)
        {
            if (n % 2 == 0)
            {
                // we have pair(s) of chars
                max_len += n;
            }
            else
            {
                // odd means there will be a char in the middle
                middle = 1;
                // get no. of chars that can be paired
                max_len += (n / 2) * 2;
            }
        }
        return max_len + middle;
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
