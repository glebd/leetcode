#include <gtest/gtest.h>

#include <vector>

class Solution
{
public:
    static int search_range(const std::vector<int>& nums, int start, int size, int target)
    {
        if (size <= 0)
            return -1;
        int mid = start + size / 2;
        int mid_num = nums[mid];
        if (mid_num == target)
            return mid;
        if (target < mid_num)
            return search_range(nums, start, size / 2, target);
        return search_range(nums, mid + 1, size / 2 - 1, target);
    }

    static int search(std::vector<int>& nums, int target)
    {
        return search_range(nums, 0, static_cast<int>(nums.size()), target);
    }
};

TEST(BinarySearch, Test1)
{
    std::vector<int> data = {-1, 0, 3, 5, 9, 12};
    ASSERT_EQ(Solution::search(data, 9), 4);
}

TEST(BinarySearch, Test2)
{
    std::vector<int> data = {-1, 0, 3, 5, 9, 12};
    ASSERT_EQ(Solution::search(data, 2), -1);
}

TEST(BinarySearch, TestEmpty)
{
    std::vector<int> data;
    ASSERT_EQ(Solution::search(data, 9), -1);
}

TEST(BinarySearch, TestSingle)
{
    std::vector<int> data = {5};
    ASSERT_EQ(Solution::search(data, 5), 0);
}

TEST(BinarySearch, Test34)
{
    std::vector<int> data = {-1, 0, 5};
    ASSERT_EQ(Solution::search(data, 5), 2);
}
