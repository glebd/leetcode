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
    ASSERT_TRUE(true);
}
