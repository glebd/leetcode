#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:
    static std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
    {
        int& center = image[sr][sc];
        if (center == color)
            return image;
        const int old_center = center;
        center = color;
        if (sr > 0)
        {
            int& top = image[sr - 1][sc];
            if (top == old_center)
                floodFill(image, sr - 1, sc, color);
        }
        if (sc < static_cast<int>(image[sr].size()) - 1)
        {
            int& right = image[sr][sc + 1];
            if (right == old_center)
                floodFill(image, sr, sc + 1, color);
        }
        if (sr < static_cast<int>(image.size()) - 1)
        {
            int& bottom = image[sr + 1][sc];
            if (bottom == old_center)
                floodFill(image, sr + 1, sc, color);
        }
        if (sc > 0)
        {
            int& left = image[sr][sc - 1];
            if (left == old_center)
                floodFill(image, sr, sc - 1, color);
        }
        return image;
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
