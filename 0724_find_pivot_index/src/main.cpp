#include <gtest/gtest.h>

#include <numeric>
#include <vector>

class Solution
{
public:
    int pivotIndex(const std::vector<int>& nums)
    {
        if (nums.empty())
            return -1;

        const size_t size = nums.size();
        int pivot_value = nums[0];
        int left_sum = 0;
        int right_sum = std::accumulate(std::next(nums.cbegin()), nums.cend(), 0);
        for (size_t pivot = 0; pivot < size; ++pivot)
        {
            if (left_sum == right_sum)
                return static_cast<int>(pivot);

            left_sum += pivot_value;
            if (pivot < size - 1)
                pivot_value = nums[pivot + 1];
            right_sum -= pivot_value;
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

TEST(PivotIndex, LastPivot)
{
    const std::vector<int> input = {1, -1, 0};
    Solution solution;
    ASSERT_EQ(solution.pivotIndex(input), 2);
}
