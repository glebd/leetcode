#include <gtest/gtest.h>

#include <stack>
#include <vector>

class Solution
{
public:
    static std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
    {
        int& center_color = image[sr][sc];
        if (center_color == color)
            return image;
        const int old_color = center_color;
        center_color = color;
        if (sr > 0)
        {
            int& top = image[sr - 1][sc];
            if (top == old_color)
                floodFill(image, sr - 1, sc, color);
        }
        if (sc < static_cast<int>(image[sr].size()) - 1)
        {
            int& right = image[sr][sc + 1];
            if (right == old_color)
                floodFill(image, sr, sc + 1, color);
        }
        if (sr < static_cast<int>(image.size()) - 1)
        {
            int& bottom = image[sr + 1][sc];
            if (bottom == old_color)
                floodFill(image, sr + 1, sc, color);
        }
        if (sc > 0)
        {
            int& left = image[sr][sc - 1];
            if (left == old_color)
                floodFill(image, sr, sc - 1, color);
        }
        return image;
    }
};

struct Coordinate
{
    int row{};
    int col{};
};

class IterSolution
{
public:
    static std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color)
    {
        int& center_color = image[sr][sc];
        if (center_color == color)
            return image;
        const int old_color = center_color;
        Coordinate start{sr, sc};
        std::stack<Coordinate> todo{{start}};
        while (!todo.empty())
        {
            auto cur = todo.top();
            int& pixel = image[cur.row][cur.col];
            pixel = color;
            todo.pop();
            if (cur.row > 0 && image[cur.row - 1][cur.col] == old_color)
                todo.push({cur.row - 1, cur.col});
            if (cur.col < static_cast<int>(image[cur.row].size()) - 1 && image[cur.row][cur.col + 1] == old_color)
                todo.push({cur.row, cur.col + 1});
            if (cur.row < static_cast<int>(image.size()) - 1 && image[cur.row + 1][cur.col] == old_color)
                todo.push({cur.row + 1, cur.col});
            if (cur.col > 0 && image[cur.row][cur.col - 1] == old_color)
                todo.push({cur.row, cur.col - 1});
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

TEST(IterFloodFill, Test1)
{
    std::vector<std::vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    const std::vector<std::vector<int>> expected = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
    const auto actual = IterSolution::floodFill(image, 1, 1, 2);
    ASSERT_EQ(actual, expected);
}

TEST(IterFloodFill, Test2)
{
    std::vector<std::vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
    const std::vector<std::vector<int>> expected = {{0, 0, 0}, {0, 0, 0}};
    const auto actual = IterSolution::floodFill(image, 0, 0, 0);
    ASSERT_EQ(actual, expected);
}

TEST(IterFloodFill, Test250)
{
    std::vector<std::vector<int>> image = {{0, 0, 0}, {1, 1, 0}};
    const std::vector<std::vector<int>> expected = {{0, 0, 0}, {2, 2, 0}};
    const auto actual = IterSolution::floodFill(image, 1, 1, 2);
    ASSERT_EQ(actual, expected);
}
