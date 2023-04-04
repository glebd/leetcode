#include "pch.h"

class Solution
{
public:
    static int maxProfit(std::vector<int>& prices)
    {
        int max_diff = 0;
        for (size_t buy_index = 0; buy_index < prices.size(); ++buy_index)
        {
            const int buy_price = prices[buy_index];
            for (size_t sell_index = buy_index + 1; sell_index < prices.size(); ++sell_index)
            {
                const int diff = prices[sell_index] - buy_price;
                max_diff = std::max(max_diff, diff);
            }
        }
        return max_diff;
    }
};

TEST(BestTimeToBuyAndSellStock, Test1)
{
    std::vector<int> stock{7, 1, 5, 3, 6, 4};
    ASSERT_EQ(Solution::maxProfit(stock), 5);
}

TEST(BestTimeToBuyAndSellStock, Test2)
{
    std::vector<int> stock{7, 6, 4, 3, 1};
    ASSERT_EQ(Solution::maxProfit(stock), 0);
}

TEST(BestTimeToBuyAndSellStock, TestEmpty)
{
    std::vector<int> stock;
    ASSERT_EQ(Solution::maxProfit(stock), 0);
}
