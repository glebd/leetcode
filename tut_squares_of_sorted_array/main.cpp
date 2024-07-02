#include <vector>

#include <gtest/gtest.h>

class Solution
{
public:
  static std::vector<int> sortedSquares(std::vector<int>& nums)
  {
    return nums;
  }
};

TEST(SquaresOfSortedArray, Test1)
{
  std::vector<int> nums = {-4, -1, 0, 3, 10};
  std::vector<int> expected = {0, 1, 9, 16, 100};
  auto const actual = Solution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SquaresOfSortedArray, Test2)
{
  std::vector<int> nums = {-7, -3, 2, 3, 11};
  std::vector<int> expected = {4, 9, 9, 49, 121};
  auto const actual = Solution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SquaresOfSortedArray, Test3)
{
  std::vector<int> nums = {1};
  std::vector<int> expected = {1};
  auto const actual = Solution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}
