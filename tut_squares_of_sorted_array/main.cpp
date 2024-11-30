#include <algorithm>
#include <vector>
#include <ranges>

#include <gtest/gtest.h>

// https://leetcode.com/explore/interview/card/leetcodes-interview-crash-course-data-structures-and-algorithms/703/arraystrings/4689/

// Runtime: 27 ms (beats 36%)
// Memory Usage: 29.4 MB (beats 39%)
class TrivialSolution
{
public:
  static std::vector<int> sortedSquares(std::vector<int>& nums)
  {
    // replace each element with its square
    for (int& n: nums)
    {
      n = n * n;
    }
    // sort the resulting vector
    std::ranges::sort(nums);
    return nums;
  }
};

//Runtime: 17 ms (beats 86%)
//Memory Usage: 28.4 MB (beats 65%)
// Speed up just by not using std::ssize()? Mad!
// https://leetcode.com/problems/squares-of-a-sorted-array/editorial/
class OptSolution
{
public:
  static std::vector<int> sortedSquares(std::vector<int>& nums)
  {
    int const size = static_cast<int>(nums.size());
    if (!size)
      return nums;
    // Define empty result array of the same size as input.
    // Fill it backwards with already-sorted values by looking at the 2 converging indexes into the input array.
    std::vector<int> res(size);
    int i1 = 0;
    int i2 = size - 1;
    int i = i2;
    while (i >= 0)
    {
      int const n1 = nums[i1];
      int const n2 = nums[i2];
      int const n1sq = n1 * n1;
      int const n2sq = n2 * n2;
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
