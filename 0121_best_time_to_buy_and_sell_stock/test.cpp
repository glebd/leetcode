#include "pch.h"

class Solution
{
public:
    static int maxProfit(std::vector<int>& prices)
    {
        int min_price = -1;
        int max_diff = 0;
        for (const int cur_price : prices)
        {
            if (min_price == -1)
                min_price = cur_price;
            max_diff = std::max(max_diff, cur_price - min_price);
            min_price = std::min(min_price, cur_price);
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
