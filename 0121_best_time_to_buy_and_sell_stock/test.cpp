#include "pch.h"

class Solution
{
public:
    static int maxProfit(std::vector<int>& prices)
    {
        return 0;
    }
};

TEST(BestTimeToBuyAndSellStock, Test1)
{
    std::vector<int> stock{7, 1, 5, 3, 6, 4};
    ASSERT_EQ(Solution::maxProfit(stock), 5);
}

TEST(BestTimeToBuyAndSellStock, Test2)
{
    std::vector<int> stock{7,6,4,3,1};
    ASSERT_EQ(Solution::maxProfit(stock), 0);
}

TEST(BestTimeToBuyAndSellStock, TestEmpty)
{
    std::vector<int> stock;
    ASSERT_EQ(Solution::maxProfit(stock), 0);
}
