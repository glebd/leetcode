#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

using namespace std;
using namespace testing;

class Solution
{
public:
    vector<int> runningSum(vector<int> nums)
    {
        if (nums.empty())
            throw runtime_error("Empty input data");
        for (int i = 1; i < static_cast<int>(nums.size()); ++i)
        {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};

TEST(RunningSum, Test1)
{
    Solution solution;
    vector nums{1, 2, 3, 4};
    vector expected{1, 3, 6, 10};
    auto actual = solution.runningSum(nums);
    EXPECT_THAT(actual, ContainerEq(expected));
}

TEST(RunningSum, Test2)
{
    Solution solution;
    vector nums{1, 1, 1, 1, 1};
    vector expected{1, 2, 3, 4, 5};
    auto actual = solution.runningSum(nums);
    EXPECT_THAT(actual, ContainerEq(expected));
}

TEST(RunningSum, Test3)
{
    Solution solution;
    vector nums{3, 1, 2, 10, 1};
    vector expected{3, 4, 6, 16, 17};
    auto actual = solution.runningSum(nums);
    EXPECT_THAT(actual, ContainerEq(expected));
}

TEST(RunningSum, EmptyData)
{
    Solution solution;
    /*
	try
	{
		auto actual = solution.runningSum({});
		FAIL();
	}
	catch (const runtime_error& err)
	{
		ASSERT_TRUE(true);
	}
	 */
    ASSERT_THROW(solution.runningSum({}), runtime_error);
}
