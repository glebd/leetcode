#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace testing;
using namespace std::string_literals;

class Solution
{
public:
    std::vector<std::string> fizzBuzz(int n)
    {
        return {};
    }
};

TEST(FizzBuzz, Test3)
{
    Solution solution;
    auto actual = solution.fizzBuzz(3);
    std::vector expected{"1"s, "2"s, "Fizz"s};
    ASSERT_THAT(actual, ContainerEq(expected));
}

TEST(FizzBuzz, Test5)
{
    Solution solution;
    auto actual = solution.fizzBuzz(5);
    std::vector expected{"1"s, "2"s, "Fizz"s, "4"s, "Buzz"s};
    ASSERT_THAT(actual, ContainerEq(expected));
}

TEST(FizzBuzz, Test15)
{
    Solution solution;
    auto actual = solution.fizzBuzz(15);
    std::vector expected{"1"s, "2"s, "Fizz"s, "4"s, "Buzz"s, "Fizz"s, "7"s, "8"s, "Fizz"s, "Buzz"s, "11"s, "Fizz"s, "13"s, "14"s, "FizzBuzz"s};
    ASSERT_THAT(actual, ContainerEq(expected));
}
