#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:
    int pivotIndex(const std::vector<int>& nums)
    {
        const size_t size = nums.size();
        for (size_t pivot = 0; pivot < size; ++pivot)
        {
            int left_sum = 0;
            int right_sum = 0;

            for (size_t j = 0; j < pivot; ++j)
                left_sum += nums[j];
            for (size_t j = pivot + 1; j < size; ++j)
                right_sum += nums[j];
            if (left_sum == right_sum)
                return static_cast<int>(pivot);
        }

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
