#include <gtest/gtest.h>

#include <vector>

// Definition for a Node.
class Node
{
public:
    int val{};
    std::vector<Node*> children{};

    Node() = default;

    explicit Node(int _val) : val(_val)
    {
    }

    Node(int _val, std::vector<Node*> _children) : val(_val), children(std::move(_children))
    {
    }
};

class Solution
{
public:
    static std::vector<int> preorder(Node* root)
    {
        return {};
    }
};

TEST(Tree, Test1)
{
    // -1 means <null> in test data, as node value is 0 <= val <= 10^4
    std::vector<int> tree{1, -1, 3, 2, 4, -1, 5, 6};
    std::vector<int> expected{1, 3, 5, 6, 2, 4};
    auto actual = Solution::preorder(nullptr);
    ASSERT_EQ(actual, expected);
}

TEST(Tree, Test2)
{
    // -1 means <null> in test data, as node value is 0 <= val <= 10^4
    std::vector<int> tree{1, -1, 2, 3, 4, 5, -1, -1, 6, 7, -1, 8, -1, 9, 10, -1, -1, 11, -1, 12, -1, 13, -1, -1, 14};
    std::vector<int> expected{1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10};
    auto actual = Solution::preorder(nullptr);
    ASSERT_EQ(actual, expected);
}
