#include <gtest/gtest.h>

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int num_steps = 0;
        while (num > 0)
        {
            if (num & 1) // odd
                --num;
            else // even
                num /= 2;
            ++num_steps;
        }
        return num_steps;
    }
};

TEST(NumSteps, Test1)
{
    Solution solution;
    ASSERT_EQ(solution.numberOfSteps(14), 6);
}

TEST(NumSteps, Test2)
{
    Solution solution;
    ASSERT_EQ(solution.numberOfSteps(8), 4);
}

TEST(NumSteps, Test3)
{
    Solution solution;
    ASSERT_EQ(solution.numberOfSteps(123), 12);
}

TEST(NumSteps, TestZero)
{
    Solution solution;
    ASSERT_EQ(solution.numberOfSteps(0), 0);
}
