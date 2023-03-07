#include <gtest/gtest.h>

#include <string>
#include <unordered_map>

// https://leetcode.com/problems/is-subsequence/?envType=study-plan&id=level-1
class Solution
{
public:
    static bool isSubsequence(const std::string& s, const std::string& t)
    {
        std::unordered_map<char, std::vector<int>> letter_indexes;
        for (size_t i = 0; i < t.length(); ++i)
        {
            auto found = letter_indexes.find(t[i]);
            if (found == letter_indexes.end())
            {
                letter_indexes.insert({t[i], {static_cast<int>(i)}});
            }
            else
            {
                auto& indexes = found->second;
                indexes.push_back(static_cast<int>(i));
            }
        }

        int curr_match_index = -1;
        for (const char ch : s)
        {
            auto found = letter_indexes.find(ch);
            if (found == letter_indexes.end())
                return false;

            bool matched = false;
            const auto& indexes = found->second;
            for (const int index : indexes)
            {
                if (curr_match_index < index)
                {
                    curr_match_index = index;
                    matched = true;
                    break;
                }
            }

            if (!matched)
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

TEST(IsSubsequence, TestBC)
{
    ASSERT_FALSE(Solution::isSubsequence("b", "c"));
}
