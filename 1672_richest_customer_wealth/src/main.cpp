#include <gtest/gtest.h>

#include <vector>
#include <numeric>

class Solution
{
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts)
    {
        int max_wealth = 0;
        for (auto const& customer : accounts)
        {
            max_wealth = std::max(max_wealth, std::accumulate(customer.begin(), customer.end(), 0));
        }

        return max_wealth;
    }
};

TEST(Wealth, Test1)
{
    std::vector<std::vector<int>> input = {{1, 2, 3}, {3, 2, 1}};
    const int expected = 6;
    Solution solution;
    const int actual = solution.maximumWealth(input);
    ASSERT_EQ(actual, expected);
}

TEST(Wealth, Test2)
{
    std::vector<std::vector<int>> input = {{1, 5}, {7, 3}, {3, 5}};
    const int expected = 10;
    Solution solution;
    const int actual = solution.maximumWealth(input);
    ASSERT_EQ(actual, expected);
}

TEST(Wealth, Test3)
{
    std::vector<std::vector<int>> input = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
    const int expected = 17;
    Solution solution;
    const int actual = solution.maximumWealth(input);
    ASSERT_EQ(actual, expected);
}
