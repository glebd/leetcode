#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
    static int numIslands(std::vector<std::vector<char>>& grid)
    {
        return 0;
    }
};

TEST(NumberOfIslands, Test1)
{
    std::vector<std::vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    int actual = Solution::numIslands(grid);
    ASSERT_EQ(actual, 1);
}

TEST(NumberOfIslands, Test2)
{
    std::vector<std::vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    int actual = Solution::numIslands(grid);
    ASSERT_EQ(actual, 3);
}

TEST(NumberOfIslands, TestEmpty)
{
    std::vector<std::vector<char>> grid = {{}};
    int actual = Solution::numIslands(grid);
    ASSERT_EQ(actual, 0);
}
