#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:
    static std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
    {
        return {{}};
    }
};

TEST(FloodFill, Test1)
{
    std::vector<std::vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    const std::vector<std::vector<int>> expected = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
    const auto actual = Solution::floodFill(image, 1, 1, 2);
    ASSERT_EQ(actual, expected);
}

TEST(FloodFill, Test2)
{
    std::vector<std::vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
    const std::vector<std::vector<int>> expected = {{0, 0, 0}, {0, 0, 0}};
    const auto actual = Solution::floodFill(image, 0, 0, 0);
    ASSERT_EQ(actual, expected);
}
