#include <set>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

struct Coordinate
{
    int m{};
    int n{};
};

bool operator<(const Coordinate& lhs, const Coordinate& rhs)
{
    return std::tie(lhs.m, lhs.n) < std::tie(rhs.m, rhs.n);
}

struct Island
{
    std::set<Coordinate> coordinates;
};

class Solution
{
    std::set<Coordinate> checked_coordinates;
    int num_islands{0};

public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        for (int m = 0; m < static_cast<int>(grid.size()); ++m)
        {
            for (int n = 0; n < static_cast<int>(grid[m].size()); ++n)
            {
                Coordinate c{m, n};
                char ch = grid[c.m][c.n];
                if (ch == '1')
                    find_island(0, c, grid);
            }
        }
        return num_islands;
    }

    void find_island(int level, const Coordinate& coord, std::vector<std::vector<char>>& grid)
    {
        if (checked_coordinates.find(coord) != checked_coordinates.end())
            return;
        checked_coordinates.insert(coord);
        char& ch = grid[coord.m][coord.n];
        if (ch == '1')
        {
            if (coord.m > 0)
            {
                char ch_top = grid[coord.m - 1][coord.n];
                if (ch_top == '1')
                    find_island(level + 1, {coord.m - 1, coord.n}, grid);
            }
            if (coord.n < static_cast<int>(grid[coord.m].size()) - 1)
            {
                char ch_right = grid[coord.m][coord.n + 1];
                if (ch_right == '1')
                    find_island(level + 1, {coord.m, coord.n + 1}, grid);
            }
            if (coord.m < static_cast<int>(grid.size() - 1))
            {
                char ch_bottom = grid[coord.m + 1][coord.n];
                if (ch_bottom == '1')
                    find_island(level + 1, {coord.m + 1, coord.n}, grid);
            }
            if (coord.n > 0)
            {
                char ch_left = grid[coord.m][coord.n - 1];
                if (ch_left == '1')
                    find_island(level + 1, {coord.m, coord.n - 1}, grid);
            }
            ch = '3'; // was '1'
        }
        else if (ch == '0')
        {
            ch = '2'; // was '0'
        }

        if (level == 0)
        {
            // add island
            ++num_islands;
        }
    }
};

TEST(NumberOfIslands, Test1)
{
    std::vector<std::vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                           {'1', '1', '0', '1', '0'},
                                           {'1', '1', '0', '0', '0'},
                                           {'0', '0', '0', '0', '0'}};
    Solution solution;
    int actual = solution.numIslands(grid);
    ASSERT_EQ(actual, 1);
}

TEST(NumberOfIslands, Test2)
{
    std::vector<std::vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                           {'1', '1', '0', '0', '0'},
                                           {'0', '0', '1', '0', '0'},
                                           {'0', '0', '0', '1', '1'}};
    Solution solution;
    int actual = solution.numIslands(grid);
    ASSERT_EQ(actual, 3);
}

TEST(NumberOfIslands, TestEmpty)
{
    std::vector<std::vector<char>> grid = {{}};
    Solution solution;
    int actual = solution.numIslands(grid);
    ASSERT_EQ(actual, 0);
}
