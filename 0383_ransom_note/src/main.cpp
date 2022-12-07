#include <gtest/gtest.h>

#include <string>
#include <map>

class Solution
{
public:
    bool canConstruct(const std::string& ransomNote, const std::string& magazine)
    {
        std::map<char, int> char_map;
        for (const char& ch : magazine)
        {
            auto found = char_map.find(ch);
            if (found != char_map.end())
            {
                // character exists, increment value by 1
                auto& elem = *found;
                ++elem.second;
            }
            else
            {
                char_map.insert({ch, 1});
            }
        }

        bool can_construct{true};
        for (const char& ch : ransomNote)
        {
            auto found = char_map.find(ch);
            if (found == char_map.end())
            {
                // char not found, can't construct
                can_construct = false;
                break;
            }
            // char found
            auto& elem = *found;
            if (--elem.second == 0)
                char_map.erase(found);
        }

        return can_construct;
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

TEST(RansomNote, TestEmptyRansomNote)
{
    Solution solution;
    ASSERT_TRUE(solution.canConstruct("", "aab"));
}

TEST(RansomNote, TestEmptyMagazine)
{
    Solution solution;
    ASSERT_FALSE(solution.canConstruct("abc", ""));
}
