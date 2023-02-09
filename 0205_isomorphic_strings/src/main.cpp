#include <gtest/gtest.h>

#include <map>
#include <string>

class Solution
{
public:
    static bool isIsomorphic(const std::string& s, const std::string& t)
    {
        if (s.length() != t.length())
            return false;
        std::map<char, char> dict;
        std::map<char, char> dict_reverse;
        for (size_t i = 0; i < s.length(); ++i)
        {
            char sc = s[i];
            char tc = t[i];
            auto found = dict.find(sc);
            if (found != dict.end())
            {
                auto expected = *found;
                if (tc != expected.second)
                    return false;
            }
            else
            {
                auto found_reverse = dict_reverse.find(tc);
                if (found_reverse != dict_reverse.end())
                    return false;
                dict.insert({sc, tc});
                dict_reverse.insert({tc, sc});
            }
        }

        return true;
    }
};

TEST(IsomorphicStrings, TestEgg)
{
    ASSERT_TRUE(Solution::isIsomorphic("egg", "add"));
}

TEST(IsomorphicStrings, TestFoo)
{
    ASSERT_FALSE(Solution::isIsomorphic("foo", "bar"));
}

TEST(IsomorphicStrings, TestPaper)
{
    ASSERT_TRUE(Solution::isIsomorphic("paper", "title"));
}

TEST(IsomorphicStrings, TestEmpty)
{
    ASSERT_TRUE(Solution::isIsomorphic("", ""));
}

TEST(IsomorphicStrings, TestDifferentLength)
{
    ASSERT_FALSE(Solution::isIsomorphic("egg", "title"));
}

TEST(IsomorphicStrings, TestBADC)
{
    ASSERT_FALSE(Solution::isIsomorphic("badc", "baba"));
}

