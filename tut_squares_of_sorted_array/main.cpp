#include <algorithm>
#include <vector>

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
      n = n * n;
    }
    std::sort(std::begin(nums), std::end(nums));
    return nums;
  }
};

//Runtime: 26 ms (beats 42%)
//Memory Usage: 28.4 MB (beats 81%)
//Just because of std::size()?
class OptSolution
{
public:
  static std::vector<int> sortedSquares(std::vector<int>& nums)
  {
    int const size = static_cast<int>(std::ssize(nums));
    if (!size)
      return nums;
    std::vector<int> res(size);
    int i1 = 0;
    int i2 = size - 1;
    int i = i2;
    while (i >= 0)
    {
      int n1 = nums[i1];
      int n2 = nums[i2];
      int n1sq = n1 * n1;
      int n2sq = n2 * n2;
      if (n1sq >= n2sq)
      {
        res[i] = n1sq;
        ++i1;
      }
      else
      {
        res[i] = n2sq;
        --i2;
      }
      --i;
    }
    return res;
  }
};

TEST(SquaresOfSortedArrayTrivial, Test1)
{
  std::vector<int> nums = {-4, -1, 0, 3, 10};
  std::vector<int> expected = {0, 1, 9, 16, 100};
  auto const actual = TrivialSolution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SquaresOfSortedArrayTrivial, Test2)
{
  std::vector<int> nums = {-7, -3, 2, 3, 11};
  std::vector<int> expected = {4, 9, 9, 49, 121};
  auto const actual = TrivialSolution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SquaresOfSortedArrayTrivial, Test3)
{
  std::vector<int> nums = {1};
  std::vector<int> expected = {1};
  auto const actual = TrivialSolution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SquaresOfSortedArrayOpt, Test1)
{
  std::vector<int> nums = {-4, -1, 0, 3, 10};
  std::vector<int> expected = {0, 1, 9, 16, 100};
  auto const actual = OptSolution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SquaresOfSortedArrayOpt, Test2)
{
  std::vector<int> nums = {-7, -3, 2, 3, 11};
  std::vector<int> expected = {4, 9, 9, 49, 121};
  auto const actual = OptSolution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}

TEST(SquaresOfSortedArrayOpt, Test3)
{
  std::vector<int> nums = {1};
  std::vector<int> expected = {1};
  auto const actual = OptSolution::sortedSquares(nums);
  ASSERT_EQ(actual, expected);
}
