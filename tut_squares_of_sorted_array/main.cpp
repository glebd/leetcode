#include <vector>
#include <algorithm>

#include <gtest/gtest.h>

// https://leetcode.com/explore/interview/card/leetcodes-interview-crash-course-data-structures-and-algorithms/703/arraystrings/4689/

// Runtime: 27 ms (beats 36%)
// Memory Usage: 29.4 MB (beats 39%)
class TrivialSolution
{
public:
  static std::vector<int> sortedSquares(std::vector<int>& nums)
  {
    for (int& n: nums)
    {
      n = n*n;
    }
    std::sort(std::begin(nums), std::end(nums));
    return nums;
  }
};

TEST(SquaresOfSortedArray, Test1)
{
  std::vector<int> nums = {-4, -1, 0, 3, 10};
  std::vector<int> expected = {0, 1, 9, 16, 100};
  auto const actual = TrivialSolution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SquaresOfSortedArray, Test2)
{
  std::vector<int> nums = {-7, -3, 2, 3, 11};
  std::vector<int> expected = {4, 9, 9, 49, 121};
  auto const actual = TrivialSolution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SquaresOfSortedArray, Test3)
{
  std::vector<int> nums = {1};
  std::vector<int> expected = {1};
  auto const actual = TrivialSolution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}
