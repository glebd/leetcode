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
        std::vector<std::string> result(n);
        for (int i = 0; i < n; ++i)
        {
            const int number = i + 1;
            std::string out;
            const bool div3 = number % 3 == 0;
            const bool div5 = number % 5 == 0;
            if (!div3 && !div5)
            {
                out = std::to_string(number);
            }
            else
            {
                if (div3) out = "Fizz";
                if (div5) out += "Buzz";
            }

            result[i] = out;
        }
        return result;
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
    std::vector expected{"1"s,    "2"s,    "Fizz"s, "4"s,    "Buzz"s, "Fizz"s, "7"s,       "8"s,
                         "Fizz"s, "Buzz"s, "11"s,   "Fizz"s, "13"s,   "14"s,   "FizzBuzz"s};
    ASSERT_THAT(actual, ContainerEq(expected));
}
