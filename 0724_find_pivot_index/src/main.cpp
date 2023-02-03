#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:
    int pivotIndex(const std::vector<int>& nums)
    {
        return -1;
    }
};

TEST(PivotIndex, Test1)
{
    const std::vector<int> input = {1, 7, 3, 6, 5, 6};
    Solution solution;
    ASSERT_EQ(solution.pivotIndex(input), 3);
}

TEST(PivotIndex, Test2)
{
    const std::vector<int> input = {1, 2, 3};
    Solution solution;
    ASSERT_EQ(solution.pivotIndex(input), -1);
}

TEST(PivotIndex, Test3)
{
    const std::vector<int> input = {2, 1, -1};
    Solution solution;
    ASSERT_EQ(solution.pivotIndex(input), 0);
}

TEST(PivotIndex, TestEmpty)
{
    Solution solution;
    ASSERT_EQ(solution.pivotIndex({}), -1);
}
